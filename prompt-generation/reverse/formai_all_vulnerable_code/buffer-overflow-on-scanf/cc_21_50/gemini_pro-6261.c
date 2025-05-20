//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  int grid[100][100];
  int newgrid[100][100];

  printf("Enter the size of the grid: ");
  scanf("%d", &n);

  printf("Enter the initial values of the grid:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  printf("The initial grid is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  for (k = 0; k < 10; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        m = i - 1;
        n = i + 1;
        o = j - 1;
        p = j + 1;

        if (m < 0) {
          m = n - 1;
        }
        if (n >= n) {
          n = 0;
        }
        if (o < 0) {
          o = p - 1;
        }
        if (p >= n) {
          p = 0;
        }

        q = grid[m][o] + grid[m][j] + grid[m][p] + grid[i][o] + grid[i][p] + grid[n][o] + grid[n][j] + grid[n][p];

        if (grid[i][j] == 1) {
          if (q < 2 || q > 3) {
            newgrid[i][j] = 0;
          } else {
            newgrid[i][j] = 1;
          }
        } else if (grid[i][j] == 0) {
          if (q == 3) {
            newgrid[i][j] = 1;
          } else {
            newgrid[i][j] = 0;
          }
        }
      }
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        grid[i][j] = newgrid[i][j];
      }
    }

    printf("The grid after %d generations is:\n", k + 1);
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}