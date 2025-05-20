//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROBOT_WIDTH 10
#define ROBOT_HEIGHT 10

int main() {
  char robot[ROBOT_HEIGHT][ROBOT_WIDTH];
  int x = 0, y = 0;
  char direction = 'N';

  // Initialize the robot's position and orientation
  for (int i = 0; i < ROBOT_HEIGHT; i++) {
    for (int j = 0; j < ROBOT_WIDTH; j++) {
      robot[i][j] = ' ';
    }
  }
  robot[y][x] = '@';

  // Get the user's input
  while (1) {
    char input;
    scanf(" %c", &input);

    // Move the robot
    switch (input) {
      case 'w':
        if (y > 0) {
          robot[y][x] = ' ';
          y--;
          robot[y][x] = '@';
        }
        break;
      case 's':
        if (y < ROBOT_HEIGHT - 1) {
          robot[y][x] = ' ';
          y++;
          robot[y][x] = '@';
        }
        break;
      case 'a':
        if (x > 0) {
          robot[y][x] = ' ';
          x--;
          robot[y][x] = '@';
        }
        break;
      case 'd':
        if (x < ROBOT_WIDTH - 1) {
          robot[y][x] = ' ';
          x++;
          robot[y][x] = '@';
        }
        break;
      case 'q':
        return 0;
    }

    // Print the robot's position
    printf("\n");
    for (int i = 0; i < ROBOT_HEIGHT; i++) {
      for (int j = 0; j < ROBOT_WIDTH; j++) {
        printf("%c", robot[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}