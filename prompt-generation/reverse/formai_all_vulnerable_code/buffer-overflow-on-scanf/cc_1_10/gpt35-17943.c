//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>

int main() {
   
   int userOption, elevation = 0, direction = 0;

   do {
      printf("\nPlease choose an option:");
      printf("\n1. Increase Elevation");
      printf("\n2. Decrease Elevation");
      printf("\n3. Move Forward");
      printf("\n4. Move Backward");
      printf("\n5. Move Left");
      printf("\n6. Move Right");
      printf("\n7. Quit");

      scanf("%d", &userOption);

      switch(userOption) {

         case 1:
            elevation++;
            printf("\nElevation increased to: %d", elevation);
            break;

         case 2:
            elevation--;
            printf("\nElevation decreased to: %d", elevation);
            break;

         case 3:
            direction++;
            printf("\nMoved forward. Current direction: %d", direction);
            break;

         case 4:
            direction--;
            printf("\nMoved backward. Current direction: %d", direction);
            break;

         case 5:
            direction -= 10;
            printf("\nMoved left. Current direction: %d", direction);
            break;

         case 6:
            direction += 10;
            printf("\nMoved right. Current direction: %d", direction);
            break;

         case 7:
            printf("\nExiting program...");
            break;

         default:
            printf("\nInvalid option, please choose again.");
            break;
      }
   } while(userOption != 7);

   return 0;
}