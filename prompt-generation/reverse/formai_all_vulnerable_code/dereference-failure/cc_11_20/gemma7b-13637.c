//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    int **arr;
    int i, j, k;

    // Allocate memory for the array
    arr = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++)
    {
        arr[i] = (int*)malloc(5 * sizeof(int));
    }

    // Initialize the array
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation simulation
    for (z = 0; z < 100; z++)
    {
        // Randomly choose a cell
        x = rand() % 5;
        y = rand() % 5;

        // If the cell is not already saturated, saturate it
        if (arr[x][y] == 0)
        {
            arr[x][y] = 1;

            // Check the four neighbors of the cell
            for (k = -1; k <= 1; k++)
            {
                for (i = -1; i <= 1; i++)
                {
                    if (x + k >= 0 && x + k < 5 && y + i >= 0 && y + i < 5 && arr[x + k][y + i] == 0)
                    {
                        arr[x + k][y + i] = 1;
                    }
                }
            }
        }
    }

    // Print the array
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < 5; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}