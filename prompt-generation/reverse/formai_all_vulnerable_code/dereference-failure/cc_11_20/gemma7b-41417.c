//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIM_SIZE 256

int main()
{
    int **grid = NULL;
    int **percolation_matrix = NULL;
    int i, j, k, sim_size;

    // Allocate memory for the grid and percolation matrix
    sim_size = MAX_SIM_SIZE;
    grid = (int**)malloc(sim_size * sizeof(int*));
    percolation_matrix = (int**)malloc(sim_size * sizeof(int*));
    for (i = 0; i < sim_size; i++)
    {
        grid[i] = (int*)malloc(sim_size * sizeof(int));
        percolation_matrix[i] = (int*)malloc(sim_size * sizeof(int));
    }

    // Initialize the grid and percolation matrix
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            grid[i][j] = 0;
            percolation_matrix[i][j] = 0;
        }
    }

    // Simulate percolation
    k = 0;
    while (k < MAX_SIM_SIZE)
    {
        // Randomly choose a cell
        i = rand() % sim_size;
        j = rand() % sim_size;

        // If the cell is not already saturated and the percolation matrix is not full
        if (grid[i][j] == 0 && percolation_matrix[i][j] == 0)
        {
            // Saturate the cell
            grid[i][j] = 1;

            // Check if the cell is a border cell
            if (i == 0 || j == 0 || i == sim_size - 1 || j == sim_size - 1)
            {
                // Percolation occurs
                percolation_matrix[i][j] = 1;
            }
            else
            {
                // Check if the neighboring cells are saturated
                if (grid[i - 1][j] == 1 || grid[i + 1][j] == 1 || grid[i][j - 1] == 1 || grid[i][j + 1] == 1)
                {
                    // Percolation occurs
                    percolation_matrix[i][j] = 1;
                }
            }
        }

        k++;
    }

    // Print the percolation matrix
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            printf("%d ", percolation_matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            free(grid[i][j]);
            free(percolation_matrix[i][j]);
        }
        free(grid[i]);
        free(percolation_matrix[i]);
    }
    free(grid);
    free(percolation_matrix);

    return 0;
}