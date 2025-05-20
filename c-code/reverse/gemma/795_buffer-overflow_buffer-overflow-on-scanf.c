#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int joy_x, joy_y, speed, direction;

  // Read joystick input
  scanf(" %d %d ", &joy_x, &joy_y);

  // Normalize input values
  if (joy_x > 100) joy_x = 100;
  if (joy_x < -100) joy_x = -100;
  if (joy_y > 100) joy_y = 100;
  if (joy_y < -100) joy_y = -100;

  // Calculate speed and direction
  speed = (joy_x * 2) / 100 + (joy_y * 2) / 100;
  direction = (joy_x > 0) ? 1 : -1;

  // Control vehicle
  switch (direction) {
    case 1:
      printf("Going forward at %d km/h\n", speed);
      break;
    case -1:
      printf("Going backward at %d km/h\n", speed);
      break;
  }

  return 0;
}
