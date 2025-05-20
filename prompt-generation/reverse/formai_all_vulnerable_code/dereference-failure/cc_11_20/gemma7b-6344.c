//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define DIM 5
#define MAX_ITER 1000

int main()
{
    int **grid = NULL;
    int i, j, k, iter = 0;
    char command;

    // Allocate memory for the grid
    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    while (iter < MAX_ITER)
    {
        printf("Enter command (p/f/s): ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'p':
                printf("Enter row and column: ");
                scanf(" %d %d", &i, &j);
                grid[i][j] = 1;
                break;
            case 'f':
                printf("Enter row and column: ");
                scanf(" %d %d", &i, &j);
                grid[i][j] = 0;
                break;
            case 's':
                for (k = 0; k < DIM; k++)
                {
                    for (i = 0; i < DIM; i++)
                    {
                        printf("%d ", grid[k][i]);
                    }
                    printf("\n");
                }
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        iter++;
    }

    // Free the memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}