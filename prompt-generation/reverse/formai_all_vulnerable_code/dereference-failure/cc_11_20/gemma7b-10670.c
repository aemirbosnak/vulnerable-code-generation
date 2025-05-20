//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    // Create a 2D array to store the game of life cells
    int **cells = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        cells[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the cells
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            cells[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Randomly activate some cells
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (rand() % 10 == 0)
            {
                cells[r][c] = 1;
            }
        }
    }

    // Simulate life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (cells[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (cells[r][c] == 1)
                {
                    if (neighbors < 2)
                    {
                        cells[r][c] = 0;
                    }
                    else if (neighbors > 3)
                    {
                        cells[r][c] = 0;
                    }
                }
                else
                {
                    if (neighbors == 3)
                    {
                        cells[r][c] = 1;
                    }
                }
            }
        }
    }

    // Print the final cells
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < ROWS; r++)
    {
        free(cells[r]);
    }
    free(cells);

    return 0;
}