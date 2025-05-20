#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int speed = 0, direction = 0, distance = 0, time = 0;

  // Control loop
  while (1) {
    // Get input from remote control
    int input = getchar();

    // Update direction and speed based on input
    switch (input) {
      case 'w':
        direction = 1;
        break;
      case 's':
        direction = -1;
        break;
      case 'a':
        speed = -1;
        break;
      case 'd':
        speed = 1;
        break;
    }

    // Calculate distance traveled
    distance += speed * time;

    // Update time
    time++;

    // Print distance traveled
    printf("Distance traveled: %d\n", distance);
  }

  return 0;
}
