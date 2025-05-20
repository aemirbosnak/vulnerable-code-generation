//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 512

int main()
{
  int **grid = NULL;
  int sim_size = MAX_SIM_SIZE;
  int num_percolation_steps = 1000;

  // Allocate memory for the grid
  grid = (int *)malloc(sim_size * sim_size * sizeof(int));
  if (grid == NULL)
  {
    return 1;
  }

  // Initialize the grid
  for (int r = 0; r < sim_size; r++)
  {
    for (int c = 0; c < sim_size; c++)
    {
      grid[r][c] = 0;
    }
  }

  // Simulate percolation
  for (int step = 0; step < num_percolation_steps; step++)
  {
    // Randomly choose a cell
    int row = rand() % sim_size;
    int column = rand() % sim_size;

    // If the cell is not already saturated and the neighboring cells are saturated,
    // then saturate the cell
    if (grid[row][column] == 0 &&
      (grid[row - 1][column] == 1 || grid[row + 1][column] == 1 ||
      grid[row][column - 1] == 1 || grid[row][column + 1] == 1))
    {
      grid[row][column] = 1;
    }
  }

  // Print the final grid
  for (int r = 0; r < sim_size; r++)
  {
    for (int c = 0; c < sim_size; c++)
    {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  free(grid);

  return 0;
}