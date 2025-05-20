//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 50
#define MAX_SIM_STEPS 1000

int main()
{
    int **grid = NULL;
    int num_active_sites = 0;
    int simulation_steps = 0;

    // Allocate memory for the grid
    grid = (int *)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Simulate the percolating water
    for (simulation_steps = 0; simulation_steps < MAX_SIM_STEPS && num_active_sites < GRID_SIZE * GRID_SIZE; simulation_steps++)
    {
        // Randomly choose a site
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        // If the site is not active and the neighboring sites are active, activate the site
        if (grid[x][y] == 0 && (grid[x - 1][y] || grid[x + 1][y] || grid[x][y - 1] || grid[x][y + 1]))
        {
            grid[x][y] = 1;
            num_active_sites++;
        }
    }

    // Print the active sites
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}