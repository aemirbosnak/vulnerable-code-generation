//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// define function to move vehicle forward
void moveForward(int *position) {
  *position += 10;
  printf("Vehicle moved forward to position %d.\n", *position);
}

// define function to move vehicle backward
void moveBackward(int *position) {
  *position -= 10;
  printf("Vehicle moved backward to position %d.\n", *position);
}

// define function to turn vehicle left
void turnLeft(int *direction) {
  *direction -= 90;
  if(*direction < 0) {
    *direction += 360;
  }
  printf("Vehicle turned left to face direction %d.\n", *direction);
}

// define function to turn vehicle right
void turnRight(int *direction) {
  *direction += 90;
  if(*direction >= 360) {
    *direction -= 360;
  }
  printf("Vehicle turned right to face direction %d.\n", *direction);
}

int main() {
  // initialize vehicle position and direction
  int position = 0;
  int direction = 0;

  // print starting position and direction
  printf("Vehicle starting at position %d, facing direction %d.\n", position, direction);

  // loop to simulate remote control commands
  while(1) {
    // ask user for input
    printf("Enter command (F = move forward, B = move backward, L = turn left, R = turn right, Q = quit): ");
    char input;
    scanf(" %c", &input);

    // check user input and call appropriate function
    switch(input) {
      case 'F':
        moveForward(&position);
        break;
      case 'B':
        moveBackward(&position);
        break;
      case 'L':
        turnLeft(&direction);
        break;
      case 'R':
        turnRight(&direction);
        break;
      case 'Q':
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid command.\n");
    }
  }
  return 0;
}