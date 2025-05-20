//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of grid
#define P 0.6 // probability of site being open

int main() {

  srand(time(0)); // seed for random number generator

  // initialize variables
  int i, j, count, open_sites;
  int grid[N][N];
  int connected[N][N] = {0};

  // create initial grid
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if ((double) rand() / RAND_MAX < P) {
        grid[i][j] = 1; // site is open
        open_sites++;
      } else {
        grid[i][j] = 0; // site is closed
      }
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // check for percolation
  do {
    count = 0;
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        if (grid[i][j] == 1 && connected[i][j] == 0) {
          count++;
          connected[i][j] = 1;
          if (i > 0 && connected[i-1][j] == 1) connected[i][j] = 1;
          if (i < N-1 && connected[i+1][j] == 1) connected[i][j] = 1;
          if (j > 0 && connected[i][j-1] == 1) connected[i][j] = 1;
          if (j < N-1 && connected[i][j+1] == 1) connected[i][j] = 1;
        }
      }
    }
  } while (count != 0);

  // output results
  if (connected[0][0] && connected[N-1][N-1]) {
    printf("Percolation achieved with probability %.2f\n", P);
  } else {
    printf("Percolation not achieved with probability %.2f\n", P);
  }
  printf("%d out of %d sites are open\n", open_sites, N*N);

  return 0;
}