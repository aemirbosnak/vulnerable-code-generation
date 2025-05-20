//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a grid of cells
    int cells[MAX_CELLS] = {0};

    // Evolve the cells for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_CELLS; i++)
        {
            int num_neighbors = 0;
            for (int j = -1; j <= 1; j++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (cells[i + j] && cells[i + j] != i)
                    {
                        num_neighbors++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (cells[i] == 1 && num_neighbors < 2)
            {
                cells[i] = 0;
            }
            else if (cells[i] == 0 && num_neighbors == 3)
            {
                cells[i] = 1;
            }
        }

        // Print the grid
        for (int i = 0; i < MAX_CELLS; i++)
        {
            printf("%d ", cells[i]);
        }
        printf("\n");
    }

    return 0;
}