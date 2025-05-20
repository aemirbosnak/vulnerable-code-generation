//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Remote Control Vehicle simulation!\n\n");

  // declare and initialize variables
  int speed = 0;
  int direction = 0;
  char command = ' ';
  
  // loop until user exits
  while (command != 'x') {
    // display menu and prompt user for input
    printf("Current speed: %d\tCurrent direction: %d\n", speed, direction);
    printf("What would you like to do?\n");
    printf("(f)orward, (b)ackward, (l)eft, (r)ight, (s)top, e(x)it\n");
    scanf(" %c", &command);
    
    // process user input
    switch (command) {
      case 'f':
        direction = 0;
        printf("Going forward\n");
        break;
      case 'b':
        direction = 180;
        printf("Going backward\n");
        break;
      case 'l':
        direction = (direction - 10) % 360;
        printf("Turning left\n");
        break;
      case 'r':
        direction = (direction + 10) % 360;
        printf("Turning right\n");
        break;
      case 's':
        speed = 0;
        printf("Stopping\n");
        break;
      case 'x':
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid command. Please try again.\n");
    }

    // randomly adjust speed
    if (command != 's' && command != 'x') {
      speed = rand() % 10 + 1;
      printf("Speed set to %d\n", speed);
    }
    
    printf("\n");
  }

  return 0;
}