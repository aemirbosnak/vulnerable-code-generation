//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main() {
  int n, m, i, j, iteration = 0;
  double p;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  printf("Enter the number of columns: ");
  scanf("%d", &m);

  printf("Enter the probability of a cell being occupied: ");
  scanf("%lf", &p);

  // Allocate memory for the grid
  int **grid = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    grid[i] = (int *)malloc(m * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      grid[i][j] = rand() % 2 == 0 ? 1 : 0;
    }
  }

  // Percolation simulation
  while (!grid[0][0] && iteration < MAX_ITERATIONS) {
    iteration++;

    // Iterate over the grid
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        // If the cell is occupied and the left cell is not, and the cell is not already occupied
        if (grid[i][j] == 1 && grid[i - 1][j] == 0) {
          grid[i][j] = 1;
        }

        // If the cell is occupied and the up cell is not, and the cell is not already occupied
        if (grid[i][j] == 1 && grid[i][j - 1] == 0) {
          grid[i][j] = 1;
        }
      }
    }
  }

  // Print the final grid
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}