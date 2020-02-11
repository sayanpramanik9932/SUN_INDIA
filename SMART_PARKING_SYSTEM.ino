#include <Servo.h>

Servo myservo;

int trigPin1 = 2;     //main gate
int echoPin1 = 3;

int trigPin2 = 4;
int echoPin2 = 5;

int trigPin3 = 6;
int echoPin3 = 7;

int led1 = 12;
int led2 = 13;
boolean f= false;



void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  myservo.attach(9);

}

void loop() {

  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  if (distance1 >= 500 || distance1 <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
  }
  delay(2);
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  if (distance2 >= 500 || distance2 <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
  }
  delay(2);
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  if (distance3 >= 500 || distance3 <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor3  ");
    Serial.print(distance3);
    Serial.println("cm");
  }
  delay(200);


  if (distance2 < 50)
  {
    digitalWrite(led1, HIGH);
  }

  else if (distance2 > 50) // if the IR sensor value is < 500 then the motor will start rotating
  {
    digitalWrite(led1, LOW);
  }

  if (distance3 < 50)
  {
    digitalWrite(led2, HIGH);
  }

  else if (distance3 > 50)
  {
    digitalWrite(led2, LOW);
  }

if(distance2<50 && distance3<50)
f=false;
else
f=true;
if(f==false)
{
  if (distance1 > 1 && distance1 < 14)             //get open

  {

    myservo.write(180); // sets the servo position according to the scaled value

    delay(2000);
  }



  else

  {

    myservo.write(0); // sets the servo position according to the scaled value

    delay(100);

  }
}



  Serial.print(duration1);
  Serial.print("cm");

  Serial.println();

  delay(100);

}


long microsecondsToCentimeters(long microseconds) {

  // The speed of sound is 340 m/s or 29 microseconds per centimeter.

  // The ping travels out and back, so to find the distance of the

  // object we take half of the distance travelled.


  return microseconds / 2 / 2;

}
