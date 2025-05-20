//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main()
{
    int sim_size, num_iter, **grid, **percolation_array, water_level, current_state;
    char **display_grid;

    // Allocate memory for the simulation
    sim_size = MAX_SIM_SIZE;
    grid = (int *)malloc(sim_size * sizeof(int));
    percolation_array = (int *)malloc(sim_size * sizeof(int));
    display_grid = (char *)malloc(sim_size * sim_size * sizeof(char));

    // Initialize the grid and percolation array
    for (int i = 0; i < sim_size; i++)
    {
        grid[i] = 0;
        percolation_array[i] = 0;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Simulate the percolations
    num_iter = 1000;
    for (int iter = 0; iter < num_iter; iter++)
    {
        // Randomly choose a cell
        int row = rand() % sim_size;
        int col = rand() % sim_size;

        // If the cell is not already saturated and the water level is high enough
        if (grid[row][col] == 0 && water_level >= 5)
        {
            // Saturate the cell
            grid[row][col] = 1;

            // Check if the cell is a border cell
            if (row == 0 || row == sim_size - 1 || col == 0 || col == sim_size - 1)
            {
                // Increase the water level
                water_level++;
            }

            // Increment the percolation array
            percolation_array[row][col] = 1;
        }
    }

    // Display the results
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            display_grid[i][j] = ' ';
            if (percolation_array[i][j] == 1)
            {
                display_grid[i][j] = '#';
            }
        }
    }

    printf("Percolation Simulation Results:\n");
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            printf("%c ", display_grid[i][j]);
        }
        printf("\n");
    }

    free(grid);
    free(percolation_array);
    free(display_grid);

    return 0;
}