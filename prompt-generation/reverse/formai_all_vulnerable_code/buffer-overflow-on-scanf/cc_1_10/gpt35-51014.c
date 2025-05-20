//FormAI DATASET v1.0 Category: Smart home automation ; Style: scientific
#include <stdio.h>

typedef struct {
   int temperature;
   int humidity; 
} SensorData;

typedef struct {
   int lightOn;
   int airConditionerOn;
   int heaterOn;
} Actuators;

int main() {
   SensorData sensorData;
  
   printf("Enter the current temperature:\n");
   scanf("%d", &sensorData.temperature);
  
   printf("Enter the current humidity:\n");
   scanf("%d", &sensorData.humidity);
  
   Actuators actuators = {0, 0, 0};
    
   if (sensorData.temperature <= 20) {
       // Turn on heater
       actuators.heaterOn = 1;
   } 
   else if (sensorData.temperature >= 30) {
       // Turn on air conditioner
       actuators.airConditionerOn = 1;
   }
   if (sensorData.humidity >= 80) {
       // Turn off lights
       actuators.lightOn = 0;
   }
   else {
       // Turn on lights
       actuators.lightOn = 1;
   }
  
   // Print current sensor values
   printf("Current temperature: %d\n", sensorData.temperature);
   printf("Current humidity: %d\n", sensorData.humidity);
  
   // Print current actuator values
   printf("Light is %s\n", actuators.lightOn ? "on" : "off");
   printf("Air conditioner is %s\n", actuators.airConditionerOn ? "on" : "off");
   printf("Heater is %s\n", actuators.heaterOn ? "on" : "off");
  
   return 0;
}