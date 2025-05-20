//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 20

int main()
{
    int **percolation_array;
    int size;
    int num_iter;
    int i, j, k;
    int current_state;
    int next_state;

    // Allocate memory for the percolation array
    percolation_array = (int *)malloc(MAX_PERCOLATION_SIZE * MAX_PERCOLATION_SIZE * sizeof(int));
    size = MAX_PERCOLATION_SIZE;

    // Initialize the percolation array
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            percolation_array[i][j] = 0;
        }
    }

    // Set the initial state of the system
    percolation_array[0][0] = 1;
    percolation_array[0][1] = 1;
    percolation_array[1][0] = 1;

    // Simulate the percolation process
    num_iter = 0;
    current_state = 0;
    next_state = 1;

    while (current_state != next_state)
    {
        next_state = current_state;

        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (percolation_array[i][j] == 1)
                {
                    // Check if the cell is in the top row
                    if (i == 0)
                    {
                        // Set the cell to the next state if it has at least one neighbor in the same state
                        if (percolation_array[i][j+1] == 1)
                        {
                            percolation_array[i][j] = next_state;
                        }
                    }
                    // Check if the cell is in the left row
                    else if (j == 0)
                    {
                        // Set the cell to the next state if it has at least one neighbor in the same state
                        if (percolation_array[i-1][j] == 1)
                        {
                            percolation_array[i][j] = next_state;
                        }
                    }
                    // Check if the cell is in the right row
                    else if (j == size-1)
                    {
                        // Set the cell to the next state if it has at least one neighbor in the same state
                        if (percolation_array[i][j-1] == 1)
                        {
                            percolation_array[i][j] = next_state;
                        }
                    }
                    // Check if the cell is in the bottom row
                    else if (i == size-1)
                    {
                        // Set the cell to the next state if it has at least one neighbor in the same state
                        if (percolation_array[i+1][j] == 1)
                        {
                            percolation_array[i][j] = next_state;
                        }
                    }
                }
            }
        }

        current_state = next_state;

        num_iter++;
    }

    // Print the final state of the system
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", percolation_array[i][j]);
        }
        printf("\n");
    }

    printf("Number of iterations: %d\n", num_iter);

    // Free the memory allocated for the percolation array
    free(percolation_array);

    return 0;
}