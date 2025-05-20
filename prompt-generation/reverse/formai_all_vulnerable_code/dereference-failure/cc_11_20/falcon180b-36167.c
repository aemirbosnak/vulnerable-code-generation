//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define NUM_TRIALS 1000
#define THRESHOLD 0.5

int main() {
  int i, j, num_occupied;
  int **grid;
  double avg_occupancy = 0.0;
  int num_trials = 0;

  grid = (int **) malloc(MAX_SIZE * sizeof(int *));
  for (i = 0; i < MAX_SIZE; i++) {
    grid[i] = (int *) malloc(MAX_SIZE * sizeof(int));
  }

  srand(time(NULL));

  for (i = 0; i < NUM_TRIALS; i++) {
    num_occupied = 0;
    for (j = 0; j < MAX_SIZE; j++) {
      grid[j][0] = rand() % 2;
      num_occupied += grid[j][0];
    }

    for (j = 1; j < MAX_SIZE; j++) {
      for (i = 1; i < MAX_SIZE; i++) {
        if (grid[i][j-1] == 1 && rand() % 2 == 0) {
          grid[i][j] = 1;
          num_occupied++;
        } else if (grid[i][j-1] == 1 && rand() % 2 == 1) {
          grid[i][j] = 0;
          num_occupied--;
        } else {
          grid[i][j] = 0;
        }
      }
    }

    avg_occupancy += (double) num_occupied / MAX_SIZE;
    num_trials++;
  }

  printf("Average occupancy: %.2f\n", avg_occupancy / num_trials);

  for (i = 0; i < MAX_SIZE; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}