//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 100

int main()
{
    int sim_size, num_percolation, current_state, random_num;
    int **grid;

    printf("Welcome, dear Watson, to the Percolation Simulator!\n");

    // Get the simulation size
    printf("Please enter the size of the simulation grid (in number of squares): ");
    scanf("%d", &sim_size);

    // Allocate memory for the grid
    grid = (int *)malloc(sim_size * sim_size * sizeof(int));
    for (int i = 0; i < sim_size * sim_size; i++)
    {
        grid[i] = 0;
    }

    // Simulate the number of percolations
    printf("How many percolations do you want to simulate? ");
    scanf("%d", &num_percolation);

    for (int n = 0; n < num_percolation; n++)
    {
        // Generate a random number
        random_num = rand() % sim_size;

        // Percolate the square
        grid[random_num] = 1;
    }

    // Print the grid
    printf("Here is the resulting grid:\n");
    for (int r = 0; r < sim_size; r++)
    {
        for (int c = 0; c < sim_size; c++)
        {
            printf("%d ", grid[r * sim_size + c]);
        }
        printf("\n");
    }

    // Free the memory
    free(grid);

    return 0;
}