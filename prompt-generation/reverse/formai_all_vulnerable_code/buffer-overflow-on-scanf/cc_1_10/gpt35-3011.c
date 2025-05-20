//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int batteryLevel = 100;
   int speed = 0;
   int direction = 0;
   int distance = 0;

   while (batteryLevel > 0) {
      char input;
      printf("Enter command (F: Forward, B: Backward, L: Left, R: Right, S: Stop): ");
      scanf(" %c", &input);

      switch (input) {
         case 'F':
            printf("Moving forward...\n");
            speed = 10;
            direction = 0;
            break;

         case 'B':
            printf("Moving backward...\n");
            speed = -10;
            direction = 0;
            break;

         case 'L':
            printf("Turning left...\n");
            speed = 5;
            direction = -1;
            break;

         case 'R':
            printf("Turning right...\n");
            speed = 5;
            direction = 1;
            break;

         case 'S':
            printf("Stopping...\n");
            speed = 0;
            direction = 0;
            break;

         default:
            printf("Invalid input.\n");
            continue;
      }

      distance += direction * speed;
      batteryLevel -= abs(speed);

      printf("Distance traveled: %d\n", distance);
      printf("Battery level: %d\n", batteryLevel);
   }

   printf("Battery depleted, vehicle shutting down.\n");

   return 0;
}