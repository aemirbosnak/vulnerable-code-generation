//FormAI DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int xPos = 0, yPos = 0; // initial position of the robot
  int direction; // variable to store direction
  int steps; // variable to store number of steps
  char move; // variable to store user input for movement

  srand(time(NULL)); // seeding random number generator with current time

  printf("Welcome to the Mind-Bending Robot Movement Control Program!\n");

  while(1) { // infinite loop to keep program running

    direction = random() % 4; // generating random direction (0,1,2,3)

    switch(direction) { // using switch statement to move the robot in selected direction
      case 0: // move north
        printf("The robot moves North.\n");
        yPos += steps;
        break;
      case 1: // move east
        printf("The robot moves East.\n");
        xPos += steps;
        break;
      case 2: // move south
        printf("The robot moves South.\n");
        yPos -= steps;
        break;
      case 3: // move west
        printf("The robot moves West.\n");
        xPos -= steps;
        break;
      default:
        printf("Unknown direction! Try again.\n");
    }
    
    printf("Robot is now at position (%d,%d).\n", xPos, yPos); // print robot's current position

    printf("Would you like to move the robot? (y/n)\n"); // ask user if they want to move the robot
    scanf("%c", &move); // read user input

    if(move == 'n') { // quit program if user wants to exit
      printf("Exiting program. Goodbye!\n");
      break;
    }

    printf("How many steps would you like to take? (1-10)\n"); // ask user how many steps to take
    scanf("%d", &steps); // read user input

    if(steps<1 || steps>10) { // check if user entered valid number of steps
      printf("Invalid number of steps! Must be between 1 and 10.\n");
      continue; // skip to next iteration of loop
    }

  }

  return 0;
}