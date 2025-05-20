//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, n, m;
    printf("Enter the dimensions of the grid: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the grid
    int **grid = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Get the number of neighbors for each cell
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            int neighbors = 0;
            if(i > 0) neighbors++;
            if(i < n - 1) neighbors++;
            if(j > 0) neighbors++;
            if(j < m - 1) neighbors++;

            grid[i][j] = neighbors;
        }
    }

    // Play the Game of Life
    for(x = 0; x < 10; x++)
    {
        for(y = 0; y < 10; y++)
        {
            if(grid[x][y] == 3)
            {
                grid[x][y] = 1;
            }
            else if(grid[x][y] == 2)
            {
                grid[x][y] = 0;
            }
        }
    }

    // Print the final grid
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}