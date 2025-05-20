//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: standalone
#include <stdio.h>

// define macro constants for the remote control vehicle
#define INITIAL_POSITION_X 0
#define INITIAL_POSITION_Y 0
#define MAXIMUM_POSITION_X 10
#define MAXIMUM_POSITION_Y 10

// define function prototypes
void moveUp(int *pos_y);
void moveDown(int *pos_y);
void moveLeft(int *pos_x);
void moveRight(int *pos_x);

int main() {
  int position_x = INITIAL_POSITION_X;
  int position_y = INITIAL_POSITION_Y;
  char input;

  // display initial position of the vehicle
  printf("Remote Control Vehicle Simulation\n");
  printf("Current Position: (%d,%d)\n", position_x, position_y);

  // start the simulation loop
  do {
    printf("\nEnter a command (u/d/l/r/q): ");
    scanf(" %c", &input);

    // process the command
    switch (input) {
      case 'u':
        moveUp(&position_y);
        break;
      case 'd':
        moveDown(&position_y);
        break;
      case 'l':
        moveLeft(&position_x);
        break;
      case 'r':
        moveRight(&position_x);
        break;
      case 'q':
        printf("Ending simulation...\n");
        break;
      default:
        printf("Invalid command!\n");
        break;
    }

    // display current position of the vehicle
    printf("Current Position: (%d,%d)\n", position_x, position_y);
  } while (input != 'q');

  return 0;
}

// function to move the vehicle up
void moveUp(int *pos_y) {
  if (*pos_y < MAXIMUM_POSITION_Y) {
    (*pos_y)++;
    printf("Moving up...\n");
  } else {
    printf("Cannot move up further!\n");
  }
}

// function to move the vehicle down
void moveDown(int *pos_y) {
  if (*pos_y > INITIAL_POSITION_Y) {
    (*pos_y)--;
    printf("Moving down...\n");
  } else {
    printf("Cannot move down further!\n");
  }
}

// function to move the vehicle left
void moveLeft(int *pos_x) {
  if (*pos_x > INITIAL_POSITION_X) {
    (*pos_x)--;
    printf("Moving left...\n");
  } else {
    printf("Cannot move left further!\n");
  }
}

// function to move the vehicle right
void moveRight(int *pos_x) {
  if (*pos_x < MAXIMUM_POSITION_X) {
    (*pos_x)++;
    printf("Moving right...\n");
  } else {
    printf("Cannot move right further!\n");
  }
}