//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

const int ROWS = 10;
const int COLS = 10;

int main(int argc, char *argv[])
{
    int **grid;  // 2D array to represent the grid of cells

    grid = (int **)malloc(ROWS * sizeof(int *));

    for (int i = 0; i < ROWS; i++)
    {
        grid[i] = (int *)malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = 1; // Start with all cells alive
        }
    }

    // Simulate the rules of the game
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = 0;

            if (i > 0)
            {
                neighbors += grid[i - 1][j];
            }

            if (i < ROWS - 1)
            {
                neighbors += grid[i + 1][j];
            }

            if (j > 0)
            {
                neighbors += grid[i][j - 1];
            }

            if (j < COLS - 1)
            {
                neighbors += grid[i][j + 1];
            }

            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3))
            {
                grid[i][j] = 1;
            }
            else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                grid[i][j] = 0;
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}