//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main() {
  // Initialize variables
  int direction = RIGHT;
  int x = 0, y = 0;
  char buffer[256];

  // Game loop
  while (1) {
    // Get input from the other player
    scanf("%s", buffer);

    // Check if the input is a command
    if (buffer[0] == 'c') {
      // Get the direction of the command
      int commandDirection = buffer[1] - 'a';

      // Change direction if necessary
      if (commandDirection != direction) {
        direction = commandDirection;
      }
    }

    // Move the C robot
    switch (direction) {
      case LEFT:
        x--;
        break;
      case RIGHT:
        x++;
        break;
      case UP:
        y++;
        break;
      case DOWN:
        y--;
        break;
    }

    // Print the new position of the C robot
    printf("%d %d\n", x, y);
  }
}