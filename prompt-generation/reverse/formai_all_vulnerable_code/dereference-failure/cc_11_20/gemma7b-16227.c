//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    // Define grid size
    int x_size = MAX_SIZE;
    int y_size = MAX_SIZE;

    // Allocate memory for grid
    double **grid = (double**)malloc(x_size * sizeof(double *));
    for (int i = 0; i < x_size; i++)
    {
        grid[i] = (double *)malloc(y_size * sizeof(double));
    }

    // Initialize grid
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            grid[i][j] = 0.0;
        }
    }

    // Set boundary conditions
    grid[0][0] = 10.0;
    grid[x_size - 1][0] = 10.0;
    grid[x_size - 1][y_size - 1] = 10.0;
    grid[0][y_size - 1] = 10.0;

    // Simulate weather
    for (int time = 0; time < 1000; time++)
    {
        // Calculate diffusion
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                double sum = 0.0;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (dx == 0 && dy == 0)
                            continue;
                        sum += grid[i + dx][j + dy] * 0.25;
                    }
                }
                grid[i][j] = sum / 4.0 + 0.5 * sin(time / 100.0);
            }
        }

        // Update boundary conditions
        grid[0][0] = 10.0;
        grid[x_size - 1][0] = 10.0;
        grid[x_size - 1][y_size - 1] = 10.0;
        grid[0][y_size - 1] = 10.0;
    }

    // Print grid
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < x_size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}