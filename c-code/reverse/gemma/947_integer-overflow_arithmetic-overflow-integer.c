#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  int speed = 0, direction = 0, distance = 0;
  char input;

  while (1) {
    printf("Enter command (s/n/w/e/q): ");
    scanf("%c", &input);

    switch (input) {
      case 's':
        speed++;
        break;
      case 'n':
        speed--;
        break;
      case 'w':
        direction = 1;
        break;
      case 'e':
        direction = -1;
        break;
      case 'q':
        exit(0);
    }

    time_t start = time(NULL);
    while (time(NULL) - start < 1) {}
    distance++;

    printf("Distance traveled: %d\n", distance);
  }
}
