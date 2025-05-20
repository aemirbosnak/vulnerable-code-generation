//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int x, y, z, c, n, m, g;
    printf("Enter the size of the grid (n x m): ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of generations: ");
    scanf("%d", &g);

    // Allocate memory for the grid
    int **grid = (int **)malloc(n * sizeof(int *));
    for (x = 0; x < n; x++)
    {
        grid[x] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Set the initial state of the grid
    printf("Enter the initial state of the grid (0 for dead, 1 for alive): ");
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            scanf("%d", &grid[x][y]);
        }
    }

    // Simulate the game of life
    for (z = 0; z < g; z++)
    {
        system("clear");
        printf("Generation %d:\n", z + 1);
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < m; y++)
            {
                c = 0;
                if (x > 0)
                {
                    c++;
                }
                if (x < n - 1)
                {
                    c++;
                }
                if (y > 0)
                {
                    c++;
                }
                if (y < m - 1)
                {
                    c++;
                }
                if (grid[x][y] == 1 && c < 2)
                {
                    grid[x][y] = 0;
                }
                else if (grid[x][y] == 0 && c == 3)
                {
                    grid[x][y] = 1;
                }
            }
        }
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < m; y++)
            {
                printf("%d ", grid[x][y]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (x = 0; x < n; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}