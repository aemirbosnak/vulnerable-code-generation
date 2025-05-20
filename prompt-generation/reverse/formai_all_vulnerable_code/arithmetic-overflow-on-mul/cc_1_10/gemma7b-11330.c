//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    int **grid;
    int rows, cols;
    int i, j, iteration = 0;
    srand(time(NULL));

    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the grid
    grid = (int *)malloc(rows * cols * sizeof(int));
    for (i = 0; i < rows * cols; i++)
    {
        grid[i] = 0;
    }

    // Percolation simulation
    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Randomly select a neighbor
                    int neighbor_i = rand() % rows;
                    int neighbor_j = rand() % cols;

                    // If the neighbor is not occupied, set it to occupied
                    if (grid[neighbor_i][neighbor_j] == 0)
                    {
                        grid[neighbor_i][neighbor_j] = 1;
                    }
                }
            }
        }

        iteration++;
    }

    // Print the final grid
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}