//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

int main()
{
    int **arr = NULL;
    int i, j, k;
    int num_percolation = 0;

    arr = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(N * sizeof(int));
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < 1000; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (arr[i][j] == 1 && (arr[i-1][j] == 1 || arr[i+1][j] == 1 || arr[i][j-1] == 1 || arr[i][j+1] == 1))
                {
                    arr[i][j] = 2;
                    num_percolation++;
                }
            }
        }
    }

    printf("Number of percolations: %d\n", num_percolation);

    for (i = 0; i < N; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}