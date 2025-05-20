//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

void simulate_percolation(int **grid, int w, int h) {
  int x, y, i, j;
  srand(time(NULL));

  // Randomly activate some sites
  for (i = 0; i < w * h; i++) {
    if (rand() % 20 == 0) {
      grid[i / w][i % w] = 1;
    }
  }

  // Percolate the water
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (grid[i][j] == 1) {
        // Check the four neighbors
        if (grid[i - 1][j] == 0 && rand() % 2 == 0) {
          grid[i - 1][j] = 1;
        }
        if (grid[i + 1][j] == 0 && rand() % 2 == 0) {
          grid[i + 1][j] = 1;
        }
        if (grid[i][j - 1] == 0 && rand() % 2 == 0) {
          grid[i][j - 1] = 1;
        }
        if (grid[i][j + 1] == 0 && rand() % 2 == 0) {
          grid[i][j + 1] = 1;
        }
      }
    }
  }

  // Print the grid
  for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
      printf("%d ", grid[y][x]);
    }
    printf("\n");
  }
}

int main() {
  int **grid;
  int w, h;

  printf("Enter the width of the grid: ");
  scanf("%d", &w);

  printf("Enter the height of the grid: ");
  scanf("%d", &h);

  grid = (int **)malloc(h * sizeof(int *));
  for (int i = 0; i < h; i++) {
    grid[i] = (int *)malloc(w * sizeof(int));
  }

  simulate_percolation(grid, w, h);

  return 0;
}