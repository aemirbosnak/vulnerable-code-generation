//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void percolation_simulator(int size);
void print_grid(int grid[MAX_SIZE][MAX_SIZE]);

int main() {
  int size;
  printf("Enter the size of the grid: ");
  scanf("%d", &size);
  percolation_simulator(size);
  return 0;
}

void percolation_simulator(int size) {
  int grid[MAX_SIZE][MAX_SIZE];
  int i, j;

  srand(time(NULL));

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  print_grid(grid);

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (grid[i][j] == 1 && grid[i][j+1] == 1 && grid[i+1][j+1] == 1) {
        printf("Percolation has occurred!\n");
        return;
      }
    }
  }

  printf("No percolation has occurred.\n");
}

void print_grid(int grid[MAX_SIZE][MAX_SIZE]) {
  int i, j;
  for (i = 0; i < MAX_SIZE; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}