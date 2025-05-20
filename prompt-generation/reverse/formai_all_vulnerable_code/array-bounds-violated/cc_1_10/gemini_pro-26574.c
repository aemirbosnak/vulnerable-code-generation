//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the robot's position and orientation
int x = 0, y = 0, angle = 0;

//Define the map
char map[10][10] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

//Define the robot's movement functions
void moveForward() {
  switch (angle) {
    case 0:
      y--;
      break;
    case 90:
      x++;
      break;
    case 180:
      y++;
      break;
    case 270:
      x--;
      break;
  }
}

void moveBackward() {
  switch (angle) {
    case 0:
      y++;
      break;
    case 90:
      x--;
      break;
    case 180:
      y--;
      break;
    case 270:
      x++;
      break;
  }
}

void turnLeft() {
  angle -= 90;
  if (angle < 0) {
    angle += 360;
  }
}

void turnRight() {
  angle += 90;
  if (angle >= 360) {
    angle -= 360;
  }
}

//Define the main function
int main() {
  //Seed the random number generator
  srand(time(NULL));

  //Move the robot around the map randomly
  for (int i = 0; i < 100; i++) {
    //Get a random movement
    int movement = rand() % 4;

    //Move the robot
    switch (movement) {
      case 0:
        moveForward();
        break;
      case 1:
        moveBackward();
        break;
      case 2:
        turnLeft();
        break;
      case 3:
        turnRight();
        break;
    }

    //Check if the robot has hit a wall
    if (map[y][x] == '#') {
      //If the robot has hit a wall, move it back to its previous position
      switch (movement) {
        case 0:
          moveBackward();
          break;
        case 1:
          moveForward();
          break;
        case 2:
          turnRight();
          break;
        case 3:
          turnLeft();
          break;
      }
    }

    //Print the map
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (j == y && k == x) {
          printf("R");
        } else {
          printf("%c", map[j][k]);
        }
      }
      printf("\n");
    }

    //Wait for a key press
    getchar();
  }

  return 0;
}