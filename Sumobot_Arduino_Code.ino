//Declare Pins for the Right Motor

const int motor_pin1=5;
const int motor_pin2=6;

//Declare pins for the Left Motor

const int motor_pin3 = 10;
const int motor_pin4= 11;

//Declare pins for the photoresistors and the IR sensor

const int IRSens = 0;
const int PHOTO1=1;
const int PHOTO2=2;
const int PHOTO3=3;
const int PHOTO4=4;

//Declare photoresistors cut-off values for black-white detection

int InitVal1=120; 
int InitVal2=50; //both InitVal1 and InitVal2 are front sensors
int InitVal3 =270;
int InitVal4 =190; //both InitVal3 and InitVal4 are back sensors

//Step 2: Set up the ports

void setup(){
  //Data travels through the serial data stream at the 9600 baud rate
  Serial.begin(9600);

  //Set up motor pins
  pinMode(motor_pin1, OUTPUT);

  //Set up sensor pins
  pinMode(PHOTO1, INPUT);
  pinMode(PHOTO2, INPUT);
  pinMode(PHOTO3, INPUT);
  pinMode(PHOTO4, INPUT);

}

//Writing Functions

//prints sensor readings

void checkSens(){
  Serial.print("Distance: ");
  Serial.print(analogRead(0));
  Serial.print("\tPhoto 1: ");
  Serial.print(analogRead(PHOTO1));
  Serial.print("\tPhoto 2: ");
  Serial.print(analogRead(PHOTO2));
  Serial.print("\tPhoto 3: ");
  Serial.print(analogRead(PHOTO3));
  Serial.print("\tPhoto 4: ");
  Serial.println(analogRead(PHOTO4));

}

//This functions tells the motor to move forward

void forward(){
  analogWrite(motor_pin1,0);
  analogWrite(motor_pin2,150);
  analogWrite(motor_pin3,150);
  analogWrite(motor_pin4,0);
}

//This function stops all motors:

void halt(){
  analogWrite(motor_pin1,0);
  analogWrite(motor_pin2,0);
  analogWrite(motor_pin3,0);
  analogWrite(motor_pin4,0);
}

//Main Code

void loop(){

  checkSens(); //Get readings from sensor that can be stored as variables

  unsigned int read1 = analogRead(PHOTO1);
  unsigned int read2 = analogRead(PHOTO2);
  unsigned int read3 = analogRead(PHOTO3);
  unsigned int read4 = analogRead(PHOTO4);
  unsigned int info = analogRead(IRSens);

  //Decision Making Code

  if((read1>InitVal1)&&(read2>InitVal2)){
    //If both front sensors detect white
    halt();
  }
  else{
    forward();
  }
  }



