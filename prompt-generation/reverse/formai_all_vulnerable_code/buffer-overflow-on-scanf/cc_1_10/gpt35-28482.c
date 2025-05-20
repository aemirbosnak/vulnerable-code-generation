//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int trafficLightColor = 0;
   int timer = 0;
   int maxTime = 10; // maximum time for each signal
   int emergencyVehicle = 0; // flag variable for emergency vehicle
   int emergencyTimer = 0; // timer for emergency vehicle
    
   srand(time(0)); // random number generator
    
   printf("Traffic Light Controller\n");
    
   while (1) {
      timer++; // increment the timer
      
      if (emergencyVehicle) { // if emergency vehicle is detected
         trafficLightColor = 3; // set traffic light to green
         printf("Emergency Vehicle Detected! Green Signal.\n");
         emergencyTimer++; // increment the emergency timer
         if (emergencyTimer >= 3) { // if emergency vehicle has passed
            emergencyVehicle = 0; // reset emergency vehicle flag
            emergencyTimer = 0; // reset emergency timer
            trafficLightColor = rand() % 3; // select a random color for traffic light
            printf("Emergency Vehicle Passed. Traffic Light Reset.\n");
         }
      } else {
         if (timer >= maxTime) { // if the timer has reached maximum time
            trafficLightColor = rand() % 3; // select a random color for traffic light
            timer = 0; // reset the timer
         }
      }
      
      switch (trafficLightColor) { // traffic light color selector
         case 0:
            printf("Red Signal.\n");
            break;
         case 1:
            printf("Yellow Signal.\n");
            break;
         case 2:
            printf("Green Signal.\n");
            break;
         default:
            printf("Error: Invalid Signal.\n");
      }
      
      printf("---------\n");
      
      char input; // input variable for emergency vehicle detection
      printf("Press E to simulate Emergency Vehicle: ");
      scanf(" %c", &input);
      if (input == 'E') {
         emergencyVehicle = 1;
         printf("Emergency Vehicle Detected!\n");
      }
   }
    
   return 0; // end of program
}