//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x = 0, y = 0, d = 0;  // Position and direction
  int m[10][10] = {0};        // Map
  char c;                    // Command

  while (1) {
    scanf("%c", &c);
    switch (c) {
      case 'w':
        d = 0;
        break;
      case 's':
        d = 1;
        break;
      case 'a':
        d = 2;
        break;
      case 'd':
        d = 3;
        break;
      case 'f':
        switch (d) {
          case 0:
            y--;
            break;
          case 1:
            y++;
            break;
          case 2:
            x--;
            break;
          case 3:
            x++;
            break;
        }
        break;
      case 'b':
        switch (d) {
          case 0:
            y++;
            break;
          case 1:
            y--;
            break;
          case 2:
            x++;
            break;
          case 3:
            x--;
            break;
        }
        break;
      case 'l':
        d = (d + 1) % 4;
        break;
      case 'r':
        d = (d - 1) % 4;
        break;
      case 'q':
        return 0;
    }

    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
      printf("Error: Out of bounds.\n");
      return 1;
    }

    if (m[x][y] == 1) {
      printf("Error: Wall in front.\n");
      return 1;
    }

    m[x][y] = 1;

    printf("Position: (%d, %d)\n", x, y);
    printf("Direction: %d\n", d);
    printf("Map:\n");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        printf("%d", m[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}