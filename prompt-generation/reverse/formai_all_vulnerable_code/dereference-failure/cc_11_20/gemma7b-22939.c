//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define DIM 20
#define MAX_ITER 1000

int main() {
  int **grid = NULL;
  int i, j, iter = 0;
  srand(time(NULL));

  grid = (int **)malloc(DIM * sizeof(int *));
  for (i = 0; i < DIM; i++) {
    grid[i] = (int *)malloc(DIM * sizeof(int));
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  while (iter < MAX_ITER) {
    for (i = 0; i < DIM; i++) {
      for (j = 0; j < DIM; j++) {
        if (grid[i][j] == 1) {
          int dx[] = {1, -1, 0, 0};
          int dy[] = {0, 0, 1, -1};
          for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < DIM && y >= 0 && y < DIM && grid[x][y] == 0) {
              grid[x][y] = 1;
            }
          }
        }
      }
    }
    iter++;
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}