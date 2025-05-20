//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the robot's movement commands
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

// Define the robot's starting position
int x = 0;
int y = 0;
int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

// Define the robot's movement function
void move(char command) {
  switch (command) {
    case FORWARD:
      if (direction == 0) {
        y++;
      } else if (direction == 1) {
        x++;
      } else if (direction == 2) {
        y--;
      } else if (direction == 3) {
        x--;
      }
      break;
    case BACKWARD:
      if (direction == 0) {
        y--;
      } else if (direction == 1) {
        x--;
      } else if (direction == 2) {
        y++;
      } else if (direction == 3) {
        x++;
      }
      break;
    case LEFT:
      direction = (direction - 1 + 4) % 4;
      break;
    case RIGHT:
      direction = (direction + 1) % 4;
      break;
    case STOP:
      break;
  }
}

// Define the main function
int main() {
  // Get the robot's movement commands from the user
  char commands[100];
  printf("Enter the robot's movement commands (F, B, L, R, S): ");
  scanf("%s", commands);

  // Move the robot according to the commands
  for (int i = 0; i < strlen(commands); i++) {
    move(commands[i]);
  }

  // Print the robot's final position
  printf("The robot's final position is (%d, %d)\n", x, y);

  return 0;
}