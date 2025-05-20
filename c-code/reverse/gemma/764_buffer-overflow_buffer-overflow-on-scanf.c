#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int grid[10][10];
  int x, y;

  scanf(" %d %d ", &x, &y);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf(" %d ", &grid[i][j]);
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (grid[i][j] > 10) {
        grid[i][j] = -1;
      }
    }
  }

  return 0;
}
