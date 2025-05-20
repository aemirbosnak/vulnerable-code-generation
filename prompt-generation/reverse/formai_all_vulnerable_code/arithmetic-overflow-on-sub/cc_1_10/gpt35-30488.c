//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>

int main() {
   int droneBattery = 100;
   int droneX = 0, droneY = 0, droneZ = 0; // Drone position variables
   char command;

   printf("*** Drone Remote Control Program ***\n");

   while (droneBattery > 20) { // Keep running until battery drops to 20%
      printf("Current Battery: %d%%\n", droneBattery);
      printf("Enter your command (f = forward, r = right, l = left, b = backward, u = up, d = down, c = charge): ");
      scanf(" %c", &command); // Reading command from user

      if (command == 'c') { // If user wants to charge the drone
         printf("Drone is charging...\n");
         droneBattery = 100; // Set battery to full
      } else {
         int distance;
         printf("Enter the distance for the command: ");
         scanf("%d", &distance); // Reading distance from user

         if (command == 'f') { // Move drone forward
            droneZ += distance;
         } else if (command == 'b') { // Move drone backward
            droneZ -= distance;
         } else if (command == 'r') { // Move drone right
            droneX += distance;
         } else if (command == 'l') { // Move drone left
            droneX -= distance;
         } else if (command == 'u') { // Move drone up
            droneY += distance;
         } else if (command == 'd') { // Move drone down
            droneY -= distance;
         } else {
            printf("Invalid command!\n");
         }

         printf("Current Position: (%d,%d,%d)\n", droneX, droneY, droneZ);
         droneBattery -= distance; // Reduce battery according to distance
      }
   }

   printf("Battery too low! Returning drone home.\n");
   droneX = 0;
   droneY = 0;
   droneZ = 0;
   printf("Drone returned to home position: (%d,%d,%d)\n", droneX, droneY, droneZ);

   return 0;
}