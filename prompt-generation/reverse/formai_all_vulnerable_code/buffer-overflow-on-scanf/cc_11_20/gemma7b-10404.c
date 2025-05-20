//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **grid = NULL;
    int rows, cols;
    int generation = 0;

    // Allocate memory for the grid
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    grid = malloc(rows * sizeof(int *) + cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Game loop
    while (1)
    {
        // Print the grid
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }

        // Calculate the next generation
        int **next_grid = malloc(rows * sizeof(int *) + cols * sizeof(int));
        for (int r = 0; r < rows; r++)
        {
            next_grid[r] = malloc(cols * sizeof(int));
        }
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int num_alive = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (grid[r + dr][c + dc] == 1)
                        {
                            num_alive++;
                        }
                    }
                }
                next_grid[r][c] = (num_alive == 2) || (num_alive == 3);
            }
        }

        // Free the previous generation
        for (int r = 0; r < rows; r++)
        {
            free(grid[r]);
        }
        free(grid);

        // Copy the next generation to the grid
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                grid[r][c] = next_grid[r][c];
            }
        }

        // Increment the generation
        generation++;

        // Check if the player wants to continue
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        // Break out of the loop if the player does not want to continue
        if (answer == 'N')
        {
            break;
        }
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}