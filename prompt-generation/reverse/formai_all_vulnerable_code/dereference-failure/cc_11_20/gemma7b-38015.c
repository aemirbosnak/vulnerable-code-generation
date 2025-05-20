//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main()
{
    int sim_size = MAX_SIM_SIZE;
    int **percolation_array = NULL;
    int i, j, k, num_iter = 0;

    percolation_array = (int **)malloc(sim_size * sizeof(int *));
    for (i = 0; i < sim_size; i++)
    {
        percolation_array[i] = (int *)malloc(sim_size * sizeof(int));
    }

    // Initialize the array
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            percolation_array[i][j] = 0;
        }
    }

    // Randomly activate sites
    srand(time(NULL));
    for (k = 0; k < sim_size * sim_size; k++)
    {
        i = rand() % sim_size;
        j = rand() % sim_size;
        percolation_array[i][j] = 1;
    }

    // Percolation process
    while (!percolation_array[sim_size - 1][sim_size - 1])
    {
        num_iter++;
        for (i = 0; i < sim_size; i++)
        {
            for (j = 0; j < sim_size; j++)
            {
                if (percolation_array[i][j] == 1)
                {
                    if (percolation_array[i - 1][j] == 1 || percolation_array[i + 1][j] == 1 || percolation_array[i][j - 1] == 1 || percolation_array[i][j + 1] == 1)
                    {
                        percolation_array[i][j] = 2;
                    }
                }
            }
        }
    }

    // Print the result
    printf("Number of iterations: %d\n", num_iter);
    printf("Percolation pattern:\n");
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            printf("%d ", percolation_array[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < sim_size; i++)
    {
        free(percolation_array[i]);
    }
    free(percolation_array);

    return 0;
}