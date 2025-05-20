//FormAI DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

enum direction {NORTH, EAST, SOUTH, WEST}; //enumeration of 4 directions

int main() {
   int x = 0, y = 0; //initial position of the robot
   enum direction dir = NORTH; //default direction is North
   
   printf("Current position: (%d, %d)", x, y);
   
   while (1) { //infinite loop until program is manually stopped
      char input;
      printf("\nMove (F)orward, turn (L)eft, turn (R)ight, or (Q)uit? ");
      scanf(" %c", &input); //space before %c to consume extra newlines
      
      switch(input) {
         case 'F':
            switch(dir) {
               case NORTH:
                  y++;
                  break;
               case EAST:
                  x++;
                  break;
               case SOUTH:
                  y--;
                  break;
               case WEST:
                  x--;
                  break;
            }
            printf("Moved forward. Current position: (%d, %d)", x, y);
            break;
         case 'L':
            switch(dir) {
               case NORTH:
                  dir = WEST;
                  break;
               case EAST:
                  dir = NORTH;
                  break;
               case SOUTH:
                  dir = EAST;
                  break;
               case WEST:
                  dir = SOUTH;
                  break;
            }
            printf("Turned left. Current direction: ");
            switch(dir) { //nested switch statements to print direction name
               case NORTH:
                  printf("North");
                  break;
               case EAST:
                  printf("East");
                  break;
               case SOUTH:
                  printf("South");
                  break;
               case WEST:
                  printf("West");
                  break;
            }
            break;
         case 'R':
            switch(dir) {
               case NORTH:
                  dir = EAST;
                  break;
               case EAST:
                  dir = SOUTH;
                  break;
               case SOUTH:
                  dir = WEST;
                  break;
               case WEST:
                  dir = NORTH;
                  break;
            }
            printf("Turned right. Current direction: ");
            switch(dir) {
               case NORTH:
                  printf("North");
                  break;
               case EAST:
                  printf("East");
                  break;
               case SOUTH:
                  printf("South");
                  break;
               case WEST:
                  printf("West");
                  break;
            }
            break;
         case 'Q':
            printf("Quitting program...");
            exit(0); //terminate program
            break;
         default: //if input is not recognized, ask again
            printf("Invalid input. ");
            continue; //continue with the while loop
      }
   }
   
   return 0;
}