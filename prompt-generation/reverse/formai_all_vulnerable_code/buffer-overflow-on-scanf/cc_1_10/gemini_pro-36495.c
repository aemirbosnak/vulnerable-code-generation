//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the robot's movements
#define MOVE_FORWARD 'F'
#define MOVE_BACKWARD 'B'
#define TURN_LEFT 'L'
#define TURN_RIGHT 'R'

// Define the robot's position and orientation
int x = 0;
int y = 0;
char orientation = 'N'; // North

// Define the robot's movement function
void move(char movement) {
  switch (movement) {
    case MOVE_FORWARD:
      if (orientation == 'N') {
        y++;
      } else if (orientation == 'E') {
        x++;
      } else if (orientation == 'S') {
        y--;
      } else if (orientation == 'W') {
        x--;
      }
      break;
    case MOVE_BACKWARD:
      if (orientation == 'N') {
        y--;
      } else if (orientation == 'E') {
        x--;
      } else if (orientation == 'S') {
        y++;
      } else if (orientation == 'W') {
        x++;
      }
      break;
    case TURN_LEFT:
      if (orientation == 'N') {
        orientation = 'W';
      } else if (orientation == 'E') {
        orientation = 'N';
      } else if (orientation == 'S') {
        orientation = 'E';
      } else if (orientation == 'W') {
        orientation = 'S';
      }
      break;
    case TURN_RIGHT:
      if (orientation == 'N') {
        orientation = 'E';
      } else if (orientation == 'E') {
        orientation = 'S';
      } else if (orientation == 'S') {
        orientation = 'W';
      } else if (orientation == 'W') {
        orientation = 'N';
      }
      break;
  }
}

// Define the robot's movement sequence function
void move_sequence(char *sequence) {
  if (*sequence == '\0') {
    return;
  }
  move(*sequence);
  move_sequence(sequence + 1);
}

int main() {
  // Get the robot's movement sequence from the user
  char sequence[100];
  printf("Enter the robot's movement sequence: ");
  scanf("%s", sequence);

  // Move the robot according to the sequence
  move_sequence(sequence);

  // Print the robot's final position and orientation
  printf("The robot's final position is (%d, %d).\n", x, y);
  printf("The robot's final orientation is %c.\n", orientation);

  return 0;
}