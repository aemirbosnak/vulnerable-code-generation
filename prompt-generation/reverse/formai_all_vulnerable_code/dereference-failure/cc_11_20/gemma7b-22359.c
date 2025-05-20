//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int main()
{
    int **arr = (int **)malloc(ROWS * sizeof(int *)), i, j;

    for (i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
        for (j = 0; j < COLS; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation Simulation
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check the four neighbors
                if (arr[i - 1][j] == 0 && rand() % 2 == 0)
                    arr[i - 1][j] = 1;
                if (arr[i + 1][j] == 0 && rand() % 2 == 0)
                    arr[i + 1][j] = 1;
                if (arr[i][j - 1] == 0 && rand() % 2 == 0)
                    arr[i][j - 1] = 1;
                if (arr[i][j + 1] == 0 && rand() % 2 == 0)
                    arr[i][j + 1] = 1;
            }
        }
    }

    // Print the results
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}