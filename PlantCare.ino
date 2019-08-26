#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
const int soilMoistureSensorPin = 0;
const int lightSensorPin = 1;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  if (!SD.begin(chipSelect)) {
    while (1);
  }
}

void loop() {
  String dataString = "";

  dataString += millis();
  dataString += ",";
  dataString += String(analogRead(soilMoistureSensorPin));
  dataString += ",";
  dataString += String(analogRead(lightSensorPin));

  File dataFile = SD.open("sensors.log", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  }
  else {
    Serial.println("error opening sensors.log");
  }
}








