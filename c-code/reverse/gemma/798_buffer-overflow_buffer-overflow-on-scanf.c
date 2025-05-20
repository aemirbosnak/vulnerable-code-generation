#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  int speed, direction;

  scanf("%s", input);

  speed = input[0] - '0';
  direction = input[1] - '0';

  // Vulnerable code: no check on input size
  if (speed > 5 || direction > 3) {
    // Handle error
  }

  // Simulate vehicle movement
  switch (direction) {
    case 0:
      // Forward
      break;
    case 1:
      // Right
      break;
    case 2:
      // Left
      break;
    case 3:
      // Reverse
      break;
  }

  printf("Vehicle is moving at speed %d and direction %d.\n", speed, direction);

  return 0;
}
