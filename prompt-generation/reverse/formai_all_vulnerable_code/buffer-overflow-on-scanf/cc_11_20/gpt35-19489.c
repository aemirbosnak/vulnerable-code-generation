//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>

int main() {
  int x = 0; // x-coordinate
  int y = 0; // y-coordinate
  int direction = 0; // 0 for North, 1 for East, 2 for South, 3 for West

  printf("Starting at (%d, %d) facing North.\n", x, y);

  while (1) { // infinite loop
    char input;
    scanf("%c", &input);

    if (input == 'f') {
      if (direction == 0) {
        y++;
      } else if (direction == 1) {
        x++;
      } else if (direction == 2) {
        y--;
      } else if (direction == 3) {
        x--;
      }
      printf("Moved forward to (%d, %d) facing ", x, y);
    } else if (input == 'r') {
      direction = (direction + 1) % 4;
      printf("Turned right and facing ");
    } else if (input == 'l') {
      direction = (direction + 3) % 4;
      printf("Turned left and facing ");
    } else if (input == 'q') {
      printf("Quitting...\n");
      break; // break out of infinite loop
    } else {
      printf("Invalid input.\n");
      continue; // skip the rest of the loop and start over at the top
    }

    // print direction after moving or turning
    if (direction == 0) {
      printf("North.\n");
    } else if (direction == 1) {
      printf("East.\n");
    } else if (direction == 2) {
      printf("South.\n");
    } else if (direction == 3) {
      printf("West.\n");
    }
  }

  return 0;
}