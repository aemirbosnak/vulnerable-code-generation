//FormAI DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Robot movement control program
  // This program demonstrates the use of a protected style of coding

  // initialize variables
  int x = 0; // x coordinate of robot
  int y = 0; // y coordinate of robot
  char dir = 'N'; // direction the robot is facing

  printf("The robot is currently at (%d,%d) facing %c\n", x, y, dir);

  // loop to receive user input
  while (1) {
    // display message for user input
    printf("Enter a command (F or B to move forward/backward, L or R to turn left/right):\n");
    // initialize variable to store user input
    char cmd;
    scanf(" %c", &cmd);

    // switch statement for user input
    switch (cmd) {
      case 'F':
        // move forward
        switch (dir) {
          case 'N':
            y++;
            break;
          case 'S':
            y--;
            break;
          case 'E':
            x++;
            break;
          case 'W':
            x--;
            break;
        }
        break;
      case 'B':
        // move backward
        switch (dir) {
          case 'N':
            y--;
            break;
          case 'S':
            y++;
            break;
          case 'E':
            x--;
            break;
          case 'W':
            x++;
            break;
        }
        break;
      case 'L':
        // turn left
        switch (dir) {
          case 'N':
            dir = 'W';
            break;
          case 'S':
            dir = 'E';
            break;
          case 'E':
            dir = 'N';
            break;
          case 'W':
            dir = 'S';
            break;
        }
        break;
      case 'R':
        // turn right
        switch (dir) {
          case 'N':
            dir = 'E';
            break;
          case 'S':
            dir = 'W';
            break;
          case 'E':
            dir = 'S';
            break;
          case 'W':
            dir = 'N';
            break;
        }
        break;
      default:
        // handle invalid input
        printf("Invalid command. Please enter F, B, L, or R.\n");
    }
    // display updated position and direction of robot
    printf("The robot is now at (%d,%d) facing %c\n", x, y, dir);
  }

  return 0;
}