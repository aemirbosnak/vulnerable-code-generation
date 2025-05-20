#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int grid[10][10];
  int i, j, x, y, n, m;

  scanf(" %d %d ", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf(" %d ", &grid[i][j]);
    }
  }

  scanf(" %d %d ", &x, &y);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (grid[i][j] == x && grid[i][j] == y) {
        printf(" Found! ");
        return 0;
      }
    }
  }

  printf(" Not found. ");
  return 0;
}
