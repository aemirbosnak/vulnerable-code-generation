//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

// Define state of devices
bool livingRoomLightState = false;
bool bedroomLightState = false;
bool airConditionerState = false;

void turnOnLivingRoomLight() {
   livingRoomLightState = true;
   printf("Living room light is turned on.\n");
}

void turnOffLivingRoomLight() {
   livingRoomLightState = false;
   printf("Living room light is turned off.\n");
}

void turnOnBedroomLight() {
   bedroomLightState = true;
   printf("Bedroom light is turned on.\n");
}

void turnOffBedroomLight() {
   bedroomLightState = false;
   printf("Bedroom light is turned off.\n");
}

void turnOnAirConditioner() {
   airConditionerState = true;
   printf("Air conditioner is turned on.\n");
}

void turnOffAirConditioner() {
   airConditionerState = false;
   printf("Air conditioner is turned off.\n");
}

int main() {
   // Assume initial state of devices is off
   printf("Welcome to Smart Home Automation System!\n");
   printf("All devices are currently off.\n");

   char command;
   while (true) {
      printf("Please enter a command (L = Living Room Light, B = Bedroom Light, A = Air Conditioner): ");
      scanf(" %c", &command);

      switch (command) {
         case 'L':
            if (livingRoomLightState) {
               turnOffLivingRoomLight();
            } else {
               turnOnLivingRoomLight();
            }
            break;

         case 'B':
            if (bedroomLightState) {
               turnOffBedroomLight();
            } else {
               turnOnBedroomLight();
            }
            break;

         case 'A':
            if (airConditionerState) {
               turnOffAirConditioner();
            } else {
               turnOnAirConditioner();
            }
            break;

         default:
            printf("Invalid command. Please enter an appropriate command.\n");
            break;
      }
   }

   return 0;
}