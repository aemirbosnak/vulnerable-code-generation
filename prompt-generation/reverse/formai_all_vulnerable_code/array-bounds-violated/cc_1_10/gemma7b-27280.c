//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

int main() {
  int map[MAP_SIZE][MAP_SIZE] = {{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  int pac_man_x = 0;
  int pac_man_y = 0;

  int direction = 1;

  while (1) {
    switch (direction) {
      case 1:
        pac_man_y--;
        break;
      case 2:
        pac_man_x++;
        break;
      case 3:
        pac_man_y++;
        break;
      case 4:
        pac_man_x--;
        break;
    }

    if (map[pac_man_y][pac_man_x] == 1) {
      direction = (direction + 1) % 4;
    }

    map[pac_man_y][pac_man_x] = 2;

    printf("%c", map[pac_man_y][pac_man_x]);

    if (pac_man_x == MAP_SIZE - 1 && pac_man_y == MAP_SIZE - 1) {
      printf("You win!");
      break;
    }
  }

  return 0;
}