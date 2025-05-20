//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *));
    for(int i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            if(arr[i][j] == 1)
            {
                arr[i][j] = 2;
                // Percolation
                if(i > 0 && arr[i - 1][j] == 1)
                {
                    arr[i - 1][j] = 2;
                }
                if(j > 0 && arr[i][j - 1] == 1)
                {
                    arr[i][j - 1] = 2;
                }
            }
        }
    }

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}