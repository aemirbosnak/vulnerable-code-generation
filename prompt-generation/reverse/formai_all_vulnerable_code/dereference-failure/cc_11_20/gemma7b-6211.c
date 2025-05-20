//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 100

int main()
{
  int size = MAX_PERCOLATION_SIZE;
  int **grid = NULL;
  int **visited = NULL;
  int iterations = 0;

  // Allocate memory
  grid = (int **)malloc(size * sizeof(int *));
  visited = (int **)malloc(size * sizeof(int *));

  // Initialize grid and visited
  for (int r = 0; r < size; r++)
  {
    grid[r] = (int *)malloc(size * sizeof(int));
    visited[r] = (int *)malloc(size * sizeof(int));

    for (int c = 0; c < size; c++)
    {
      grid[r][c] = 0;
      visited[r][c] = 0;
    }
  }

  // Randomly assign saturated cells
  srand(time(NULL));
  for (int i = 0; i < 1000; i++)
  {
    int r = rand() % size;
    int c = rand() % size;
    grid[r][c] = 1;
  }

  // Percolation algorithm
  while (!all_visited(visited, size) && iterations < 1000)
  {
    for (int r = 0; r < size; r++)
    {
      for (int c = 0; c < size; c++)
      {
        if (visited[r][c] || grid[r][c] != 1)
          continue;

        int num_neighbours = 0;
        for (int dr = -1; dr <= 1; dr++)
        {
          for (int dc = -1; dc <= 1; dc++)
          {
            if (r + dr < 0 || r + dr >= size || c + dc < 0 || c + dc >= size)
              continue;

            if (grid[r + dr][c + dc] == 1 && visited[r + dr][c + dc] == 0)
              num_neighbours++;
          }
        }

        if (num_neighbours > 0)
        {
          visited[r][c] = 1;
          grid[r][c] = 2;
        }
      }
    }

    iterations++;
  }

  // Print the final grid
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%d ", grid[r][c]);
    }

    printf("\n");
  }

  // Free memory
  for (int r = 0; r < size; r++)
  {
    free(grid[r]);
    free(visited[r]);
  }

  free(grid);
  free(visited);

  return 0;
}

int all_visited(int **visited, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      if (visited[r][c] == 0)
        return 0;
    }
  }

  return 1;
}