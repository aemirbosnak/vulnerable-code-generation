//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

int main() {
  char command;
  int direction = LEFT;

  while (1) {
    printf("Enter command (L/R/F/B): ");
    scanf(" %c", &command);

    switch (command) {
      case 'L':
        direction = LEFT;
        break;
      case 'R':
        direction = RIGHT;
        break;
      case 'F':
        direction = FORWARD;
        break;
      case 'B':
        direction = BACKWARD;
        break;
      default:
        printf("Invalid command.\n");
        break;
    }

    switch (direction) {
      case LEFT:
        printf("Drone moving left.\n");
        break;
      case RIGHT:
        printf("Drone moving right.\n");
        break;
      case FORWARD:
        printf("Drone moving forward.\n");
        break;
      case BACKWARD:
        printf("Drone moving backward.\n");
        break;
    }
  }

  return 0;
}