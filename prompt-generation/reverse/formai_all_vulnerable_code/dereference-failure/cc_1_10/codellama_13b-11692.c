//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
// Percolation Simulator in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100 // number of grid points
#define R 100 // number of runs

// function to generate a random number between 0 and 1
double rand_uniform() {
  return (double)rand() / (double)RAND_MAX;
}

// function to check if a site is open
int is_open(int i, int j) {
  return (i == 0 || i == N-1 || j == 0 || j == N-1);
}

// function to check if a site is percolated
int is_percolated(int** grid, int i, int j) {
  if (i == 0 || j == 0 || i == N-1 || j == N-1) {
    return 1;
  }

  if (grid[i][j] == 1) {
    if (grid[i-1][j] == 1 || grid[i+1][j] == 1 || grid[i][j-1] == 1 || grid[i][j+1] == 1) {
      return 1;
    }
  }

  return 0;
}

// function to run the simulation
void run_simulation() {
  int i, j;
  int** grid = malloc(N * sizeof(int*));

  for (i = 0; i < N; i++) {
    grid[i] = malloc(N * sizeof(int));
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      grid[i][j] = 0;
    }
  }

  // initialize the grid
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (is_open(i, j)) {
        grid[i][j] = 1;
      }
    }
  }

  // run the simulation
  int t = 0;
  while (t < R) {
    int i = rand() % N;
    int j = rand() % N;
    if (grid[i][j] == 0) {
      grid[i][j] = 1;
      t++;
    }
  }

  // print the results
  printf("Percolation results: \n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // free the memory
  for (i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);
}

int main() {
  srand(time(NULL));
  run_simulation();
  return 0;
}