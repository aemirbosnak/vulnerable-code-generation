//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdlib.h>
#include <time.h>

#define DIM 50

int main()
{
    int **arr = NULL;
    int i, j, k;
    int seed = time(NULL);

    // Allocate memory
    arr = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize array
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation
    for (k = 0; k < 1000; k++)
    {
        i = rand() % DIM;
        j = rand() % DIM;
        if (arr[i][j] == 0)
        {
            arr[i][j] = 1;
            // Spread water
            if (i > 0)
                arr[i - 1][j] = 1;
            if (i < DIM - 1)
                arr[i + 1][j] = 1;
            if (j > 0)
                arr[i][j - 1] = 1;
            if (j < DIM - 1)
                arr[i][j + 1] = 1;
        }
    }

    // Print the array
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}