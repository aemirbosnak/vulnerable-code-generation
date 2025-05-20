//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Declare the robot's position and facing direction
int x = 0, y = 0, facing = 0;

// Declare the map
char map[10][10] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
  {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
  {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

// Declare the movement functions
void moveForward();
void turnLeft();
void turnRight();

// Define the movement functions
void moveForward() {
  switch (facing) {
    case 0: // North
      y--;
      break;
    case 1: // East
      x++;
      break;
    case 2: // South
      y++;
      break;
    case 3: // West
      x--;
      break;
  }

  // Check if the robot has hit a wall
  if (map[y][x] == '#') {
    printf("Ouch! The robot has hit a wall.\n");
    exit(1);
  }
}

void turnLeft() {
  facing--;
  if (facing < 0) {
    facing = 3;
  }
}

void turnRight() {
  facing++;
  if (facing > 3) {
    facing = 0;
  }
}

// Main function
int main() {
  // Get the robot's initial position and facing direction from the user
  printf("Enter the robot's initial position (x, y): ");
  scanf("%d %d", &x, &y);
  printf("Enter the robot's initial facing direction (0 = North, 1 = East, 2 = South, 3 = West): ");
  scanf("%d", &facing);

  // Get the robot's movement commands from the user
  char commands[100];
  printf("Enter the robot's movement commands: ");
  scanf("%s", commands);

  // Execute the robot's movement commands
  for (int i = 0; i < strlen(commands); i++) {
    switch (commands[i]) {
      case 'F':
        moveForward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
    }
  }

  // Print the robot's final position and facing direction
  printf("The robot's final position is (%d, %d).\n", x, y);
  printf("The robot's final facing direction is ");
  switch (facing) {
    case 0:
      printf("North.\n");
      break;
    case 1:
      printf("East.\n");
      break;
    case 2:
      printf("South.\n");
      break;
    case 3:
      printf("West.\n");
      break;
  }

  return 0;
}