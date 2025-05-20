//FormAI DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   // initialize movement variables
   int positionX = 0;
   int positionY = 0;
   int facing = 0; // 0 = north, 1 = east, 2 = south, 3 = west

   // prompt user for input
   printf("Enter commands for C Robot movement: ");
   char commands[100];
   scanf("%s", commands);

   // parse and execute commands
   for(int i = 0; commands[i] != '\0'; ++i) {
      char command = commands[i];
      switch(command) {
         case 'F':
            switch(facing) {
               case 0:
                  ++positionY;
                  break;
               case 1:
                  ++positionX;
                  break;
               case 2:
                  --positionY;
                  break;
               case 3:
                  --positionX;
                  break;
            }
            break;
         case 'L':
            facing = (facing + 3) % 4; // turn left by 90 degrees
            break;
         case 'R':
            facing = (facing + 1) % 4; // turn right by 90 degrees
            break;
         default:
            printf("Invalid command %c\n", command);
            break;
      }
   }

   // display final position and facing direction
   printf("C Robot's final position is (%d, %d) facing ", positionX, positionY);
   switch(facing) {
      case 0:
         printf("North");
         break;
      case 1:
         printf("East");
         break;
      case 2:
         printf("South");
         break;
      case 3:
         printf("West");
         break;
   }
   printf("\n");

   return 0;
}