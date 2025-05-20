//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, p, q;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the grid
    int **grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    for (p = 0; p < k; p++)
    {
        // Randomly choose two cells
        i = rand() % n;
        j = rand() % m;

        // If both cells are empty, fill them
        if (grid[i][j] == 0)
        {
            grid[i][j] = 1;
        }
    }

    // Print the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}