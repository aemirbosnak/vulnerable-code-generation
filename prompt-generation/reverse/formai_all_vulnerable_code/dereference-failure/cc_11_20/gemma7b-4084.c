//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int **grid = NULL;
  int rows = 20;
  int cols = 20;
  int generation = 0;

  // Allocate memory for the grid
  grid = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++)
  {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      grid[r][c] = 0;
    }
  }

  // Set some initial cells to 1
  grid[10][10] = 1;
  grid[10][11] = 1;
  grid[10][12] = 1;
  grid[11][10] = 1;
  grid[11][11] = 1;
  grid[11][12] = 1;

  // Simulate game of life for 20 generations
  for (generation = 0; generation < 20; generation++)
  {
    // Calculate the number of neighbors for each cell
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        int neighbors = 0;
        // Check the cells to the north
        if (grid[r - 1][c] == 1)
        {
          neighbors++;
        }
        // Check the cells to the south
        if (grid[r + 1][c] == 1)
        {
          neighbors++;
        }
        // Check the cells to the east
        if (grid[r][c + 1] == 1)
        {
          neighbors++;
        }
        // Check the cells to the west
        if (grid[r][c - 1] == 1)
        {
          neighbors++;
        }

        // Apply the rules of life
        if (grid[r][c] == 1 && neighbors < 2)
        {
          grid[r][c] = 0;
        }
        else if (grid[r][c] == 0 && neighbors == 3)
        {
          grid[r][c] = 1;
        }
      }
    }

    // Print the grid
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        printf("%d ", grid[r][c]);
      }
      printf("\n");
    }
  }

  // Free the memory
  for (int r = 0; r < rows; r++)
  {
    free(grid[r]);
  }
  free(grid);

  return 0;
}