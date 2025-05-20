//FormAI DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>

int main() {
   int direction = 0;
   
   while (1) {
      printf("Robot is idle. Enter a direction to move (0-9) or 10 to exit: ");
      scanf("%d", &direction);
      
      switch (direction) {
         case 0:
            printf("Moving forward...\n");
            break;
         case 1:
            printf("Moving backward...\n");
            break;
         case 2:
            printf("Moving left...\n");
            break;
         case 3:
            printf("Moving right...\n");
            break;
         case 4:
            printf("Rotating clockwise...\n");
            break;
         case 5:
            printf("Rotating counter-clockwise...\n");
            break;
         case 6:
            printf("Moving up...\n");
            break;
         case 7:
            printf("Moving down...\n");
            break;
         case 8:
            printf("Taking a sensor reading...\n");
            break;
         case 9:
            printf("Performing a task...\n");
            break;
         case 10:
            printf("Exiting...\n");
            exit(0);
         default:
            printf("Invalid direction.\n");
            break;
      }
   }
   
   return 0;
}