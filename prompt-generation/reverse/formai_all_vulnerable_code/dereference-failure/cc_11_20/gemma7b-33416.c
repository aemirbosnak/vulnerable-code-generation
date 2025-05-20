//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
  // Seed the random number generator
  srand(time(NULL));

  // Create a 2D array to store the percolating cells
  int **cells = (int **)malloc(DIM * sizeof(int *));
  for (int i = 0; i < DIM; i++)
  {
    cells[i] = (int *)malloc(DIM * sizeof(int));
  }

  // Initialize the cells
  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      cells[i][j] = 0;
    }
  }

  // Simulate the percolating water
  int num_percolation = 0;
  while (num_percolation < DIM * DIM)
  {
    // Randomly select a cell
    int x = rand() % DIM;
    int y = rand() % DIM;

    // If the cell is not already percolated and its neighbors are
    if (cells[x][y] == 0 && (cells[x - 1][y] || cells[x + 1][y] || cells[x][y - 1] || cells[x][y + 1]))
    {
      // Percolate the cell
      cells[x][y] = 1;

      // Increment the number of percolated cells
      num_percolation++;
    }
  }

  // Print the percolated cells
  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the cells
  for (int i = 0; i < DIM; i++)
  {
    free(cells[i]);
  }
  free(cells);

  return 0;
}