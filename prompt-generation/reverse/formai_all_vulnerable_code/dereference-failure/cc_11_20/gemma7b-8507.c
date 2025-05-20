//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = (int **)malloc(ROWS * sizeof(int *));
    for(int r = 0; r < ROWS; r++)
    {
        grid[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the grid
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while(1)
    {
        // Calculate the next generation
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                int neighbors = 0;
                // Check the neighbors
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(grid[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Update the cell
                if(grid[r][c] == 0 && neighbors == 3)
                {
                    grid[r][c] = 1;
                }
                else if(grid[r][c] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    grid[r][c] = 0;
                }
            }
        }

        // Print the grid
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if(generation > 10)
        {
            break;
        }
    }

    // Free the memory
    for(int r = 0; r < ROWS; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}