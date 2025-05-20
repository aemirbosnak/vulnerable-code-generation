#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  int speed = 0;
  int direction = 0;

  scanf("%s", input);

  switch (input[0]) {
    case 'w':
      speed = 10;
      direction = 0;
      break;
    case 'a':
      speed = 5;
      direction = -1;
      break;
    case 's':
      speed = 0;
      direction = 0;
      break;
    case 'd':
      speed = 5;
      direction = 1;
      break;
    default:
      speed = 0;
      direction = 0;
  }

  // Drive the vehicle
  for (int i = 0; i < speed; i++) {
    // Move forward or turn left
    switch (direction) {
      case -1:
        // Turn left
        break;
      case 0:
        // Drive straight
        break;
      case 1:
        // Turn right
        break;
    }
  }

  return 0;
}
