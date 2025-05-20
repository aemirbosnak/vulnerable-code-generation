//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL)); // initialize random seed
   int battery_level = 100;
   int signal_strength = 100;
   int altitude = 0;
   int speed = 0;

   // infinite loop to simulate continuous control of drone
   while (1) {

      // check if the remote control is still connected
      if (signal_strength > 0) {
         printf("Remote control connected. Battery level: %d%%\n", battery_level);

         // adjust altitude
         if (altitude >= 0 && altitude < 100) {
            printf("Current altitude: %d meters\n", altitude);
            printf("Enter altitude adjustment (positive or negative): ");
            int adjustment;
            scanf("%d", &adjustment);
            altitude += adjustment;
         }
         else if (altitude < 0) {
            altitude = 0;
            printf("Cannot adjust altitude below 0\n");
         }
         else {
            altitude = 100;
            printf("Cannot adjust altitude above 100\n");
         }

         // adjust speed
         printf("Current speed: %d km/h\n", speed);
         printf("Enter speed adjustment (positive or negative): ");
         int adjustment;
         scanf("%d", &adjustment);
         speed += adjustment;

         // simulate battery drain
         int battery_drain = rand() % 5 + 1;
         battery_level -= battery_drain;

         // simulate signal strength loss
         int signal_loss = rand() % 5;
         if (signal_strength > signal_loss) {
            signal_strength -= signal_loss;
         }
         else {
            signal_strength = 0;
            printf("Lost connection to remote control\n");
         }
      }
      else {
         printf("Cannot control drone - no remote control signal\n");
      }

      // check if drone has crashed
      if (altitude == 0 && speed > 0) {
         printf("Drone has crashed!\n");
         break;
      }

      // check if battery is depleted
      if (battery_level <= 0) {
         printf("Battery depleted - returning to home base\n");
         break;
      }
   }

   return 0;
}