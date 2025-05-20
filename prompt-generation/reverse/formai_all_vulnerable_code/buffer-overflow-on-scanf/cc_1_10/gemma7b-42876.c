//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main()
{
    int **grid;
    int sim_size, num_percolation, i, j, x, y;
    time_t start, end;

    printf("Enter the simulation size (default is 20): ");
    scanf("%d", &sim_size);

    if (sim_size <= 0)
    {
        printf("Invalid simulation size. Exiting...\n");
        return 1;
    }

    num_percolation = rand() % MAX_SIM_SIZE;

    grid = (int **)malloc(sim_size * sizeof(int *));
    for (i = 0; i < sim_size; i++)
    {
        grid[i] = (int *)malloc(sim_size * sizeof(int));
    }

    start = time(NULL);

    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            x = rand() % MAX_SIM_SIZE;
            y = rand() % MAX_SIM_SIZE;

            if (x == y && grid[x][y] == 0)
            {
                grid[x][y] = 1;
            }
        }
    }

    end = time(NULL);

    printf("Number of percolations: %d\n", num_percolation);
    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}