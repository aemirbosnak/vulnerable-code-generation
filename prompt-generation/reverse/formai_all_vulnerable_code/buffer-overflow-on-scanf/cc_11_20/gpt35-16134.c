//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: innovative
#include <stdio.h>

int main() {
   char action;
   int altitude = 0;
   int speed = 0;
   //Initialize the drone
   printf("Initializing Drone..\n");
   printf("Drone initialized.\n");
   
   while (1) {
      //Read the user input
      printf("\nEnter action (U/D/F/B/L/R/S): ");
      scanf(" %c", &action);

      switch (action) {
         case 'U':
            altitude += 10;
            printf("\nAltitude increased by 10 feet. Altitude is now %d feet.\n",altitude);
            break;
         case 'D':
            if (altitude > 0) {
               altitude -= 10;
               printf("\nAltitude decreased by 10 feet. Altitude is now %d feet.\n",altitude);
            } else {
               printf("\nDrone already on ground, cannot go lower.\n");
            }
            break;
         case 'F':
            if (speed < 10) {
               speed++;
               printf("\nSpeed increased by 1 unit. Speed is now %d.\n",speed);
            } else {
               printf("\nMaximum speed reached.\n");
            }
            break;
         case 'B':
            if (speed > 0) {
               speed--;
               printf("\nSpeed decreased by 1 unit. Speed is now %d.\n",speed);
            } else {
               printf("\nDrone already stationary, cannot decrease speed.\n");
            }
            break;
         case 'L':
            printf("\nDrone turned left.\n");
            break;
         case 'R':
            printf("\nDrone turned right.\n");
            break;
         case 'S':
            altitude = 0;
            speed = 0;
            printf("\nDrone stopped. Altitude is %d feet and speed is %d.\n",altitude,speed);
            break;
         default:
            printf("\nInvalid action. Please try again.\n");
      }
   }
   
   return 0;
}