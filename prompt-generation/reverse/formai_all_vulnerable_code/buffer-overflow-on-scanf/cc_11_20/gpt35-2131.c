//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ada Lovelace
/*
* This program simulates the movement of a remote control car.
* The car can move forward, backward, left, and right.
* It also has a limit on how far it can move before hitting a boundary.
*/

#include <stdio.h>

#define BOUNDARY 10  // set the boundary limit to 10 units

int main() {
  int x = 0, y = 0;  // set the initial position of the car to (0,0)
  char input;  // declare the input variable

  printf("***Remote Control Car Simulation***\n");
  printf("Press 'f' to move forward, 'b' to move backward,\n");
  printf("'l' to turn left, 'r' to turn right.\n");
  printf("Press 'q' to quit the simulation.\n");

  while(1) {  // create an infinite loop to continuously prompt for input
    printf("Car position: (%d,%d)\n", x, y);
    printf("Enter command: ");
    scanf(" %c", &input);  // get input from the user

    switch(input) {
      case 'f':
        if (y < BOUNDARY) {  // check if the car has not reached the limit
          y++;  // move the car forward
          printf("Car moved forward.\n");
        } else {
          printf("Boundary reached, cannot move forward.\n");
        }
        break;
      case 'b':
        if (y > -BOUNDARY) {  // check if the car has not reached the limit
          y--;  // move the car backward
          printf("Car moved backward.\n");
        } else {
          printf("Boundary reached, cannot move backward.\n");
        }
        break;
      case 'l':
        if (x > -BOUNDARY) {  // check if the car has not reached the limit
          x--;  // turn the car left
          printf("Car turned left.\n");
        } else {
          printf("Boundary reached, cannot turn left.\n");
        }
        break;
      case 'r':
        if (x < BOUNDARY) {  // check if the car has not reached the limit
          x++;  // turn the car right
          printf("Car turned right.\n");
        } else {
          printf("Boundary reached, cannot turn right.\n");
        }
        break;
      case 'q':
        printf("Simulation ended.\n");
        return 0;  // exit the program
      default:
        printf("Invalid command, please try again.\n");
        break;
    }
  }

  return 0;
}