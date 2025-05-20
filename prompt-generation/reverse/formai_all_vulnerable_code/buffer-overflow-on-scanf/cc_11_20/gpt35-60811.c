//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
// Welcome to the happy and fun C Robot Movement Control Program!
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare and initialize the robot's current position and direction
  int x = 0;
  int y = 0;
  char direction = 'N';

  // Declare the commands for the robot to move and turn
  char move_cmds[100];
  printf("Enter a series of commands for the robot to move and turn (use F to move forward, L to turn left, R to turn right):\n");
  scanf("%s", move_cmds);

  // Loop through each command and move or turn the robot as needed
  for (int i = 0; move_cmds[i] != '\0'; i++) {
    // Move the robot forward
    if (move_cmds[i] == 'F') {
      switch (direction) {
        case 'N':
          y++;
          break;
        case 'E':
          x++;
          break;
        case 'S':
          y--;
          break;
        case 'W':
          x--;
          break;
      }
      printf("Moved the robot forward to position (%d, %d) facing %c.\n", x, y, direction);
    }
    // Turn the robot left
    else if (move_cmds[i] == 'L') {
      switch (direction) {
        case 'N':
          direction = 'W';
          break;
        case 'E':
          direction = 'N';
          break;
        case 'S':
          direction = 'E';
          break;
        case 'W':
          direction = 'S';
          break;
      }
      printf("Turned the robot left to face %c.\n", direction);
    }
    // Turn the robot right
    else if (move_cmds[i] == 'R') {
      switch (direction) {
        case 'N':
          direction = 'E';
          break;
        case 'E':
          direction = 'S';
          break;
        case 'S':
          direction = 'W';
          break;
        case 'W':
          direction = 'N';
          break;
      }
      printf("Turned the robot right to face %c.\n", direction);
    }
  }

  // Print the final position and direction of the robot
  printf("The robot's final position is (%d, %d) facing %c.\n", x, y, direction);
  printf("Yay, the robot successfully completed its movement control program!\n");

  return 0;
}