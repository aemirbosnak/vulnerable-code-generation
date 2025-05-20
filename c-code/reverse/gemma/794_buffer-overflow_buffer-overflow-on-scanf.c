#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char joy_input[10];
  int speed = 0, direction = 0;

  printf("Enter joystick input (format: 'w/a/s/d'): ");
  scanf("%s", joy_input);

  if (strlen(joy_input) > 10) {
    printf("Error: Input too long.\n");
  } else {
    speed = joy_input[0] - 'w' - 1;
    direction = joy_input[1] - 'a' - 1;

    // Implement logic to control vehicle based on speed and direction
  }

  return 0;
}
