//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *)), i, j;

    for (i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[5][5] = 1;
    arr[4][5] = 1;
    arr[3][5] = 1;
    arr[2][5] = 1;

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = 2;
                if (i - 1 >= 0)
                    arr[i - 1][j] = 2;
                if (j - 1 >= 0)
                    arr[i][j - 1] = 2;
                if (i + 1 < DIM)
                    arr[i + 1][j] = 2;
                if (j + 1 < DIM)
                    arr[i][j + 1] = 2;
            }
        }
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}