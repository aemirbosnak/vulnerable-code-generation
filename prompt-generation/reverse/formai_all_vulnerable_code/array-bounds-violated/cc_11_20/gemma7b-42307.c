//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

int main()
{
    int cells[MAX_CELLS] = {0};
    int i, j, k, l, generation = 0;

    // Initialize the game board
    for (i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = rand() % 2;
    }

    // Play the game for 10 generations
    for (generation = 0; generation < 10; generation++)
    {
        // Calculate the next generation
        for (k = 0; k < MAX_CELLS; k++)
        {
            int num_neighbors = 0;
            for (l = -1; l <= 1; l++)
            {
                if (cells[k + l] == 1)
                {
                    num_neighbors++;
                }
            }

            // Update the cell
            if (cells[k] == 1 && num_neighbors < 2)
            {
                cells[k] = 0;
            }
            else if (cells[k] == 0 && num_neighbors == 3)
            {
                cells[k] = 1;
            }
        }

        // Print the game board
        for (i = 0; i < MAX_CELLS; i++)
        {
            printf("%d ", cells[i]);
        }

        printf("\n");
    }

    return 0;
}