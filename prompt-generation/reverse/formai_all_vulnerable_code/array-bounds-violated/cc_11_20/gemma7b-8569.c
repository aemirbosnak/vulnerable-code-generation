//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

int main()
{
    int cells[MAX_CELLS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int generation = 0;

    // Game loop
    while (1)
    {
        // Print the cells
        for (int i = 0; i < MAX_CELLS; i++)
        {
            printf("%d ", cells[i]);
        }
        printf("\n");

        // Calculate the next generation
        for (int i = 0; i < MAX_CELLS; i++)
        {
            int neighbors = 0;
            for (int j = -1; j <= 1; j++)
            {
                if (cells[i + j] == 1)
                {
                    neighbors++;
                }
            }

            // Apply the rules of life
            if (cells[i] == 0 && neighbors == 3)
            {
                cells[i] = 1;
            }
            else if (cells[i] == 1 && (neighbors < 2 || neighbors > 3))
            {
                cells[i] = 0;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation >= 10)
        {
            break;
        }
    }

    return 0;
}