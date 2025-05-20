//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **grid = NULL;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Game of Life rules
    for (int t = 0; t < 10; t++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                // Check the neighbors
                if (r - 1 >= 0)
                {
                    neighbors++;
                }
                if (r + 1 < rows)
                {
                    neighbors++;
                }
                if (c - 1 >= 0)
                {
                    neighbors++;
                }
                if (c + 1 < cols)
                {
                    neighbors++;
                }

                // Apply the rules
                if (grid[r][c] == 1 && neighbors < 2)
                {
                    grid[r][c] = 0;
                }
                else if (grid[r][c] == 0 && neighbors == 3)
                {
                    grid[r][c] = 1;
                }
            }
        }
    }

    // Print the final grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}