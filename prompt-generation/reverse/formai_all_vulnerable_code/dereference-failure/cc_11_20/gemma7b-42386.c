//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10
#define MAX_ITERATIONS 1000

int main()
{
  int **grid = NULL;
  int i, j, iteration = 0;
  srand(time(NULL));

  grid = (int **)malloc(DIM * sizeof(int *));
  for (i = 0; i < DIM; i++)
  {
    grid[i] = (int *)malloc(DIM * sizeof(int));
  }

  for (i = 0; i < DIM; i++)
  {
    for (j = 0; j < DIM; j++)
    {
      grid[i][j] = rand() % 2;
    }
  }

  while (iteration < MAX_ITERATIONS)
  {
    for (i = 0; i < DIM; i++)
    {
      for (j = 0; j < DIM; j++)
      {
        if (grid[i][j] == 1)
        {
          int neighbors = 0;
          for (int r = -1; r <= 1; r++)
          {
            for (int c = -1; c <= 1; c++)
            {
              if (grid[i + r][j + c] == 1)
              {
                neighbors++;
              }
            }
          }

          if (neighbors >= 3)
          {
            grid[i][j] = 2;
          }
        }
      }
    }

    iteration++;
  }

  for (i = 0; i < DIM; i++)
  {
    free(grid[i]);
  }

  free(grid);

  return 0;
}