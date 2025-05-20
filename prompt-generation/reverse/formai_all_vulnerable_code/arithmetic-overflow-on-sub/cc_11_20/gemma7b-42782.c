//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n, i, j, k, l, m, x, y;
  char c;
  time_t t;

  x = 10;
  y = 10;

  while (1) {
    t = time(NULL);
    n = rand() % 4;

    switch (n) {
      case 0:
        c = 'w';
        break;
      case 1:
        c = 'a';
        break;
      case 2:
        c = 's';
        break;
      case 3:
        c = 'd';
        break;
    }

    switch (c) {
      case 'w':
        y++;
        break;
      case 'a':
        x--;
        break;
      case 's':
        y--;
        break;
      case 'd':
        x++;
        break;
    }

    printf("x: %d, y: %d\n", x, y);

    if (time(NULL) - t > 1) {
      break;
    }
  }

  return 0;
}