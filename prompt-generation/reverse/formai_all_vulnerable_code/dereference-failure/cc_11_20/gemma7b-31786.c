//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int size = MAX_SIZE;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    int x = size / 2;
    int y = size / 2;

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    grid[x][y] = 1;

    // Game loop
    while (1)
    {
        system("clear");

        // Print the grid
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        // Get the direction
        char direction = getchar();

        // Move the shape
        switch (direction)
        {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            default:
                break;
        }

        // Check if the shape has reached the border
        if (x < 0 || x >= size || y < 0 || y >= size)
        {
            break;
        }

        // Update the grid
        grid[x][y] = 1;
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}