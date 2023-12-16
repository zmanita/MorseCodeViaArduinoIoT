#include "arduino_secrets.h"
/*
CPEN 462 Semester IoT Project
Display messsage sent via IoT Cloud (messenger widget on dashboard) on LED
by Zarin M Manita
*/

/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/d2963a3a-fdb5-4e8f-bc68-60d9c1ccdbb8 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String msg;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/


#include "thingProperties.h"
int ledPin = 1; // led pin number 
int dit = 200; //dot is 1 unit
int dah = dit*3; //dash is 3 units
int lettergap = dit*3; //space between letters is 3 units
int wordgap = dit*7; //space between words is 7 units

void setup() {
  pinMode(ledPin, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
}

void convert(String mCode) {
  for (int i = 0; i < mCode.length() + 1; i++) {
    Serial.println(mCode.charAt(i));
    switch (mCode.charAt(i)) {
       case 'a':
        mark(dit);
        mark(dah);
        break;
      case 'b':
        mark(dah);
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 'c':
        mark(dah);
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 'd':
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case 'e':
        mark(dit);
        break;
      case 'f':
        mark(dit);
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 'g':
        mark(dah);
        mark(dah);
        mark(dit);
        break;
      case 'h':
        mark(dit);
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 'i':
        mark(dit);
        mark(dit);
        break;
      case 'j':
        mark(dit);
        mark(dah);
        mark(dah);
        mark(dah);
        break;
      case 'k':
        mark(dah);
        mark(dit);
        mark(dah);
        break;
      case 'l':
        mark(dit);
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case 'm':
        mark(dah);
        mark(dah);
        break;
      case 'n':
        mark(dah);
        mark(dit);
        break;
      case 'o':
        mark(dah);
        mark(dah);
        mark(dah);
        break;
      case 'p':
        mark(dit);
        mark(dah);
        mark(dah);
        mark(dit);
        break;
      case 'q':
        mark(dah);
        mark(dah);
        mark(dit);
        mark(dah);
        break;
      case 'r':
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 's':
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 't':
        mark(dah);
        break;
      case 'u':
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'v':
        mark(dit);
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'w':
        mark(dit);
        mark(dah);
        mark(dah);
        break;
      case 'x':
        mark(dah);
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'y':
        mark(dah);
        mark(dit);
        mark(dah);
        mark(dah);
        break;
      case 'z':
        mark(dah);
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case ' ':
        // Turn the LED off
        digitalWrite(ledPin, LOW);
        delay(lettergap); //space between characters
        break;
    }
    // Turn the LED off
    digitalWrite(ledPin, LOW);
    delay(wordgap); //space between words
  }
  digitalWrite(ledPin, LOW); //turn led off after transmission
  delay(5000); // 5 second delay after the finished message
}

void mark(int unitTime) { 
  digitalWrite(ledPin, HIGH);
  delay(unitTime);
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  // Give space between parts of the same letter...equal to one dot
  delay(dit);
}
/*
  Since Msg is READ_WRITE variable, onMsgChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMsgChange()  {
  // Add your code here to act upon Msg change
  convert(msg);
}
