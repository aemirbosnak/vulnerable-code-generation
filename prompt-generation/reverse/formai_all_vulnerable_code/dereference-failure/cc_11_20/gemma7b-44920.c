//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void game_of_life(int **grid, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check the 8 neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < size) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < size) neighbors++;
            if (r - 1 && c - 1) neighbors++;
            if (r - 1 && c + 1) neighbors++;
            if (r + 1 && c - 1) neighbors++;
            if (r + 1 && c + 1) neighbors++;

            // Apply the rules
            if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3)) grid[r][c] = 0;
        }
    }
}

int main()
{
    int size = 10;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) grid[i] = (int *)malloc(size * sizeof(int));

    // Initial grid
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;

    // Game of Life
    game_of_life(grid, size);

    // Print the final grid
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    return 0;
}