//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand (time(NULL)); //initialize random seed
   
   int x = 0, y = 0, fuel = 100; //initial values
   char direction[4] = {'N', 'E', 'S', 'W'}; //array for directions
   char input = '\0'; //initial input
   
   printf("Welcome to the remote control vehicle simulator!\n");
   printf("Your vehicle is currently at position (%d,%d) with %d fuel units\n", x, y, fuel);
   
   while(fuel > 0) { //while there is fuel left
      printf("Enter a direction (N/E/S/W) or Q to quit: ");
      scanf(" %c", &input); //get input
      
      if(input == 'Q' || input == 'q') { //if user wants to quit
         printf("Quitting simulation...\n");
         break; //exit loop
      }
      
      int randNum = rand() % 3 + 1; //generate random move distance
      printf("Moving %d units in direction %c\n", randNum, input);
      
      switch(input) { //move in chosen direction
         case 'N': y += randNum;
                   break;
         case 'E': x += randNum;
                   break;
         case 'S': y -= randNum;
                   break;
         case 'W': x -= randNum;
                   break;
         default: printf("Invalid input. Try again.\n");
                  continue; //start loop again
      }
      
      fuel -= randNum; //subtract from fuel
      printf("Vehicle is now at position (%d,%d) with %d fuel units\n", x, y, fuel);
   }
   
   if(fuel == 0) { //if fuel runs out
      printf("Your vehicle has run out of fuel!\n");
      printf("Final position: (%d,%d)\n", x, y);
   }
   
   printf("Thank you for using the remote control vehicle simulator!\n");
   
   return 0;
}