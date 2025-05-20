//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 256

#define PERCOLATION_THRESHOLD 50

int main()
{
  int sim_size = MAX_SIM_SIZE;
  int num_iter = 10000;
  int **grid = NULL;
  int **percolation_map = NULL;
  int x, y, z, i, j, k, rand_num;

  grid = (int **)malloc(sim_size * sizeof(int *));
  percolation_map = (int **)malloc(sim_size * sizeof(int *));
  for (x = 0; x < sim_size; x++)
  {
    grid[x] = (int *)malloc(sim_size * sizeof(int));
    percolation_map[x] = (int *)malloc(sim_size * sizeof(int));
  }

  srand(time(NULL));

  for (i = 0; i < num_iter; i++)
  {
    for (x = 0; x < sim_size; x++)
    {
      for (y = 0; y < sim_size; y++)
      {
        rand_num = rand() % PERCOLATION_THRESHOLD;
        if (rand_num == 0)
        {
          grid[x][y] = 1;
        }
      }
    }

    for (x = 0; x < sim_size; x++)
    {
      for (y = 0; y < sim_size; y++)
      {
        if (grid[x][y] == 1)
        {
          percolation_map[x][y] = 1;
          for (z = 0; z < sim_size; z++)
          {
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
              percolation_map[x][y] = 1;
            }
            if (x + 1 < sim_size && grid[x + 1][y] == 1)
            {
              percolation_map[x][y] = 1;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
              percolation_map[x][y] = 1;
            }
            if (y + 1 < sim_size && grid[x][y + 1] == 1)
            {
              percolation_map[x][y] = 1;
            }
          }
        }
      }
    }
  }

  for (x = 0; x < sim_size; x++)
  {
    for (y = 0; y < sim_size; y++)
    {
      printf("%d ", percolation_map[x][y]);
    }
    printf("\n");
  }

  return 0;
}