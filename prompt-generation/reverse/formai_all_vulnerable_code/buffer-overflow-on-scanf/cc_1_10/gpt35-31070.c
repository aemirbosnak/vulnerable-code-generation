//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int max_altitude = 100;
   int current_altituide = 0;
   int x_coordinate = 0;
   int y_coordinate = 0;
   int battery_life = 100;
   int speed = 10;
   int distance;
   srand(time(NULL));

   printf("Drone Remote Control System\n");
   printf("==========================\n");

   while (battery_life > 0) {
      printf("Current Location: (%d, %d)\n", x_coordinate, y_coordinate);
      printf("Battery Life: %d\n", battery_life);
      printf("Current Altitude: %d\n", current_altituide);

      if (current_altituide > max_altitude) {
         printf("Warning: Max altitude reached.\n");
      }

      // Ask for user input
      char direction; 
      int altitude_change;
      printf("Enter direction (N/E/S/W): ");
      scanf(" %c", &direction);
      distance = rand() % 20 + 10;

      switch (direction) {
         case 'N':
            y_coordinate += distance;
            break;
         case 'E':
            x_coordinate += distance;
            break;
         case 'S':
            y_coordinate -= distance;
            break;
         case 'W':
            x_coordinate -= distance;
            break;
         default:
            printf("Invalid direction.\n");
            break;
      }

      printf("Distance travelled: %d\n", distance);

      // Ask for altitude change
      printf("Enter altitude change (+/- number): ");
      scanf("%d", &altitude_change);

      if ((current_altituide + altitude_change) > max_altitude) {
         current_altituide = max_altitude;
      } else if ((current_altituide + altitude_change) < 0) {
         current_altituide = 0;
         printf("Warning: Drone crashed.\n");
         return 0;
      } else {
         current_altituide += altitude_change;
      }

      battery_life -= distance / speed;
      if (battery_life < 0) {
         battery_life = 0;
      }

   }

   printf("Battery drained. Returning to base.\n");
   return 0;
}