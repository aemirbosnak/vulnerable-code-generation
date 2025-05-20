//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Enter the dimensions of the grid: ");
    scanf("%d %d", &x, &y);

    // Create the grid
    int **grid = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        grid[i] = (int*)malloc(y * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Place the characters
    printf("Enter the positions of the characters (separated by commas): ");
    scanf("%d %d", &grid[0][0], &grid[0][1]);
    printf("Enter the positions of the feud leaders (separated by commas): ");
    scanf("%d %d", &grid[1][0], &grid[1][1]);

    // Simulate the game of life
    int generation = 0;
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                int neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (grid[i + r][j + c] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of survival and reproduction
                if (grid[i][j] == 1 && neighbors < 2)
                {
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 0 && neighbors == 3)
                {
                    grid[i][j] = 1;
                }
            }
        }

        // Print the grid
        printf("Generation %d:\n", generation++);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (grid[0][0] == grid[1][0] || grid[0][0] == grid[1][1] || grid[0][1] == grid[1][0])
        {
            break;
        }
    }

    // Free the memory
    for (int i = 0; i < x; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}