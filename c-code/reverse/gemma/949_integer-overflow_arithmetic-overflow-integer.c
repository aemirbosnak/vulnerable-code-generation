#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed = 0, direction = 1, distance = 0;
  char input;

  while (1) {
    printf("Enter command (s, n, r, q): ");
    scanf(" %c", &input);

    switch (input) {
      case 's':
        speed++;
        break;
      case 'n':
        speed--;
        break;
      case 'r':
        direction *= -1;
        break;
      case 'q':
        exit(0);
    }

    distance++;
    printf("Distance traveled: %d\n", distance);
  }

  return 0;
}
