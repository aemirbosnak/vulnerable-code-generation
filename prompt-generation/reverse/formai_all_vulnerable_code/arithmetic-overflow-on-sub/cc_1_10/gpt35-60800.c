//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int x = 0;
   int y = 0;
   int z = 0;
   srand(time(NULL)); // Seed to make random number generation more random
   
   while (1) { // Continuously loop until user quits program
      printf("Current position: (%d, %d, %d)\n", x, y, z); // Display current position of drone
      
      // Prompt user to input direction and distance they want the drone to move
      printf("Enter direction (N/E/S/W/U/D) and distance (1-10): ");
      char direction;
      scanf(" %c", &direction);
      int distance;
      scanf("%d", &distance);
      
      // Generate random factor to add variation to the drone's movement
      double factor = (rand() % 10) / 10.0;
      
      // Move the drone based on input and factor
      switch (direction) {
         case 'N':
            x += distance;
            y += factor * distance;
            break;
         case 'E':
            y += distance;
            x += factor * distance;
            break;
         case 'S':
            x -= distance;
            y -= factor * distance;
            break;
         case 'W':
            y -= distance;
            x -= factor * distance;
            break;
         case 'U':
            z += distance;
            break;
         case 'D':
            z -= distance;
            break;
         default:
            printf("Invalid direction.\n"); // If user inputs invalid direction, do nothing and continue loop
            continue;
      }
   }
   return 0; // Program should never reach this point, but included for completeness 
}