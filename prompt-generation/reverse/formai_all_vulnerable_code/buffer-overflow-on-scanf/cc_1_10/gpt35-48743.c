//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>

int main() {
   int batteryLevel = 100;
   int currentPosition = 0;
   int distanceToTravel;
   int direction;

   printf("Welcome to the RC Car Simulator!\n\n");

   while (batteryLevel > 0) {
      printf("Current Position: %d\n", currentPosition);
      printf("Battery Level: %d%%\n\n", batteryLevel);

      printf("Enter distance to travel (in meters): ");
      scanf("%d", &distanceToTravel);

      if (distanceToTravel > batteryLevel * 10) {
         printf("\nError: Insufficient battery level for travel distance. Please recharge.\n");
         continue;
      }

      printf("\nEnter direction to travel (0 for forward, 1 for backward): ");
      scanf("%d", &direction);

      if (direction == 0) {
         if (currentPosition + distanceToTravel > 100) {
            printf("\nError: Out of bounds. Please select a smaller distance to travel.\n");
            continue;
         }

         currentPosition += distanceToTravel;
      } else if (direction == 1) {
         if (currentPosition - distanceToTravel < 0) {
            printf("\nError: Out of bounds. Please select a smaller distance to travel.\n");
            continue;
         }

         currentPosition -= distanceToTravel;
      }

      batteryLevel -= distanceToTravel / 10;

      printf("\nTravel successful!\n\n");
   }

   printf("Battery level depleted. Please recharge.\n");

   return 0;
}