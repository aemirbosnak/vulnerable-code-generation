#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int speed = 0, direction = 0;

  printf("Enter joystick input (speed, direction): ");
  scanf("%d, %d", &speed, &direction);

  // Handle potentially malformed input
  if (speed < -10 || speed > 10) {
    printf("Error: Invalid speed.\n");
  } else if (direction < -1 || direction > 1) {
    printf("Error: Invalid direction.\n");
  } else {
    // Simulate vehicle movement
    printf("Vehicle moving at speed %d, direction %d.\n", speed, direction);
  }

  return 0;
}
