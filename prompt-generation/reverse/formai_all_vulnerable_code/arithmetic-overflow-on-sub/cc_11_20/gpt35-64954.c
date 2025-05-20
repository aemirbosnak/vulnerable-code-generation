//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
// This C program simulates a remote control vehicle
// The vehicle can move in different directions and perform certain actions

#include <stdio.h>
#include <stdlib.h>

int main() {

   int batteryLevel = 100;
   int speedLevel = 0;
   int direction = 0; // 0 - forward, 1 - backward, 2 - left, 3 - right
   int action = 0; // 0 - none, 1 - honk horn, 2 - turn signal left, 3 - turn signal right

   printf("Welcome to the Remote Control Vehicle Simulator!\n");
   printf("Battery level: %d%%\n", batteryLevel);

   while (batteryLevel > 0) {
       // Take user input for speed and direction
       printf("\nEnter speed level (0-5): ");
       scanf("%d", &speedLevel);

       printf("\nEnter direction (0 - forward, 1 - backward, 2 - left, 3 - right): ");
       scanf("%d", &direction);

       // Update battery level based on speed level and direction
       if (speedLevel > 0) {
           batteryLevel -= speedLevel * 2;
       }

       if (direction == 0 || direction == 1) {
           batteryLevel -= 5;
       } else {
           batteryLevel -= 3;
       }

       // Take user input for action
       printf("\nEnter action (0 - none, 1 - honk horn, 2 - turn signal left, 3 - turn signal right): ");
       scanf("%d", &action);

       // Perform action if specified
       if (action == 1) {
           printf("\nHonking horn...");
       } else if (action == 2) {
           printf("\nTurning signal left...");
       } else if (action == 3) {
           printf("\nTurning signal right...");
       }

       // Print current status
       printf("\nBattery level: %d%%", batteryLevel);
       printf("\nSpeed level: %d", speedLevel);

       if (direction == 0) {
           printf("\nDirection: forward");
       } else if (direction == 1) {
           printf("\nDirection: backward");
       } else if (direction == 2) {
           printf("\nDirection: left");
       } else if (direction == 3) {
           printf("\nDirection: right");
       }
   }

   printf("\n\nBattery drained, shutting off remote control vehicle.");

   return 0;
}