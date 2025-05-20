//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>

#define DIM 10

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    int percolate = 0;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (arr[i][j] == 1)
            {
                percolate++;
                arr[i][j] = 0;
                if (i > 0)
                {
                    arr[i - 1][j] = 1;
                }
                if (j > 0)
                {
                    arr[i][j - 1] = 1;
                }
                if (i < DIM - 1)
                {
                    arr[i + 1][j] = 1;
                }
                if (j < DIM - 1)
                {
                    arr[i][j + 1] = 1;
                }
            }
        }
    }

    printf("Number of percolations: %d\n", percolate);

    for (int i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}