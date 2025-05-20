//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>

#define DIM 10

int main() {
  int **grid = (int **)malloc(DIM * sizeof(int *));
  for (int i = 0; i < DIM; i++) {
    grid[i] = (int *)malloc(DIM * sizeof(int));
  }

  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      grid[i][j] = 0;
    }
  }

  int x = rand() % DIM;
  int y = rand() % DIM;
  grid[x][y] = 1;

  int steps = 0;
  while (1) {
    int dx = rand() % 4 - 1;
    int dy = rand() % 4 - 1;

    if (dx == -1 && grid[x - 1][y] == 0) {
      grid[x - 1][y] = 1;
      x--;
    } else if (dx == 0 && grid[x][y - 1] == 0) {
      grid[x][y - 1] = 1;
      y--;
    } else if (dx == 1 && grid[x + 1][y] == 0) {
      grid[x + 1][y] = 1;
      x++;
    } else if (dy == -1 && grid[x][y + 1] == 0) {
      grid[x][y + 1] = 1;
      y++;
    }

    steps++;
    if (grid[DIM - 1][DIM - 1] == 1) {
      break;
    }
  }

  printf("Number of steps: %d\n", steps);
  free(grid);

  return 0;
}