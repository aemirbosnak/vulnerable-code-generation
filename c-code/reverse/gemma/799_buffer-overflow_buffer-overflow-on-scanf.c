#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int joy_x, joy_y, speed, direction;

  while (1) {
    printf("Enter command (w/a/s/d/q): ");
    scanf("%c", &direction);

    switch (direction) {
      case 'w':
        speed = 10;
        break;
      case 'a':
        speed = 5;
        break;
      case 's':
        speed = 0;
        break;
      case 'd':
        speed = -5;
        break;
      case 'q':
        exit(0);
    }

    printf("Enter speed (0-10): ");
    scanf("%d", &speed);

    // Process directional commands and speed adjustments
    // ...

    // Output vehicle's status
    printf("Vehicle position: x=%d, y=%d\n", joy_x, joy_y);
    printf("Vehicle speed: %d\n", speed);
  }

  return 0;
}
