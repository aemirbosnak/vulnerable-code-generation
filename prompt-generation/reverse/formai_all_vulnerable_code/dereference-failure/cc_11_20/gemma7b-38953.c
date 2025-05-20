//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Seed the random number generator
  srand(time(NULL));

  // Create a 2D array of cells
  int **cells = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; i++)
  {
    cells[i] = (int *)malloc(10 * sizeof(int));
  }

  // Initialize the cells
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cells[i][j] = rand() % 2;
    }
  }

  // Simulate life for 10 generations
  for (int g = 0; g < 10; g++)
  {
    // Calculate the number of neighbors for each cell
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        int num_neighbors = 0;
        // Check the cells to the left
        if (i > 0)
        {
          num_neighbors++;
        }
        // Check the cells to the right
        if (i < 9)
        {
          num_neighbors++;
        }
        // Check the cells above
        if (j > 0)
        {
          num_neighbors++;
        }
        // Check the cells below
        if (j < 9)
        {
          num_neighbors++;
        }

        // Update the cell's state based on its number of neighbors
        if (cells[i][j] == 1 && num_neighbors < 2)
        {
          cells[i][j] = 0;
        }
        else if (cells[i][j] == 0 && num_neighbors == 3)
        {
          cells[i][j] = 1;
        }
      }
    }
  }

  // Print the final state of the cells
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the cells
  for (int i = 0; i < 10; i++)
  {
    free(cells[i]);
  }
  free(cells);

  return 0;
}