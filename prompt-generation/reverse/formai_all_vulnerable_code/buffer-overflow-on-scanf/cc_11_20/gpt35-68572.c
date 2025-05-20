//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() {
   int battery_level = 100;
   int flight_time = 0;
   int altitude = 0;
   int max_altitude = 100;

   srand(time(0));
   int drone_id = rand() % 1000;

   while(battery_level > 0) {
      printf("Welcome to C Drone Remote Control Program\n");
      printf("Drone ID: %d\n", drone_id);
      printf("Battery Level: %d%%\n", battery_level);
      printf("Flight Time: %d seconds\n", flight_time);
      printf("Altitude: %d meters\n", altitude);
      printf("Max Altitude: %d meters\n", max_altitude);

      // User Input for action selection
      printf("\nEnter 1 to Take off\n");
      printf("Enter 2 to Move Forward\n");
      printf("Enter 3 to Move Backward\n");
      printf("Enter 4 to Move Left\n");
      printf("Enter 5 to Move Right\n");
      printf("Enter 6 to Increase Altitude\n");
      printf("Enter 7 to Decrease Altitude\n");
      printf("Enter 8 to Land\n");
      printf("Enter any other number to Exit program\n");

      int action_choice;
      scanf("%d", &action_choice);

      switch(action_choice) {
         case 1:
            if(altitude == 0) {
               printf("Taking Off\n");
               altitude = 10;
            } else {
               printf("Invalid Action: Drone is already in the air\n");
            }
            break;
         case 2:
            if(altitude > 0) {
               printf("Moving Forward\n");
            } else {
               printf("Invalid Action: Drone is not in the air\n");
            }
            break;
         case 3:
            if(altitude > 0) {
               printf("Moving Backward\n");
            } else {
               printf("Invalid Action: Drone is not in the air\n");
            }
            break;
         case 4:
            if(altitude > 0) {
               printf("Moving Left\n");
            } else {
               printf("Invalid Action: Drone is not in the air\n");
            }
            break;
         case 5:
            if(altitude > 0) {
               printf("Moving Right\n");
            } else {
               printf("Invalid Action: Drone is not in the air\n");
            }
            break;
         case 6:
            if(altitude < max_altitude) {
               printf("Increasing Altitude\n");
               altitude += 10;
            } else {
               printf("Invalid Action: Maximum Altitude Reached\n");
            }
            break;
         case 7:
            if(altitude > 0) {
               printf("Decreasing Altitude\n");
               altitude -= 10;
            } else {
               printf("Invalid Action: Drone is already on the ground\n");
            }
            break;
         case 8:
            if(altitude > 0) {
               printf("Landing\n");
               altitude = 0;
            } else {
               printf("Invalid Action: Drone is already on the ground\n");
            }
            break;
         default:
            printf("Exiting Program\n");
            battery_level = 0;
      }

      // Update Battery Level and Flight Time
      if(altitude > 0) {
         battery_level -= 5;
         flight_time += 10;
      }
   }

   printf("Battery level too low for further operation\n");
   return 0;
}