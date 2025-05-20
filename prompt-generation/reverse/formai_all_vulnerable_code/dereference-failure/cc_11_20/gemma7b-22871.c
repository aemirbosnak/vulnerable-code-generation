//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **arr = NULL;
    int i, j, k, l, r, n, m, percolates = 0;

    // Allocate memory
    arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the array
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Randomly set some cells to 1
    n = rand() % MAX_SIZE;
    m = rand() % MAX_SIZE;
    arr[n][m] = 1;

    // Percolation algorithm
    for (k = 0; k < MAX_SIZE; k++)
    {
        for (l = 0; l < MAX_SIZE; l++)
        {
            if (arr[k][l] == 1)
            {
                r = k + 1;
                while (r < MAX_SIZE && arr[r][l] == 0)
                {
                    arr[r][l] = 1;
                    r++;
                }

                r = k - 1;
                while (r >= 0 && arr[r][l] == 0)
                {
                    arr[r][l] = 1;
                    r--;
                }

                r = l + 1;
                while (r < MAX_SIZE && arr[k][r] == 0)
                {
                    arr[k][r] = 1;
                    r++;
                }

                r = l - 1;
                while (r >= 0 && arr[k][r] == 0)
                {
                    arr[k][r] = 1;
                    r--;
                }
            }
        }
    }

    // Count the number of percolating cells
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (arr[i][j] == 1)
            {
                percolates++;
            }
        }
    }

    // Print the number of percolating cells
    printf("The number of percolating cells is: %d", percolates);

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}