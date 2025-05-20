//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *));
    for(int i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    int seed = time(NULL);
    srand(seed);

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
            int sum = 0;
            for(int r = 0; r < DIM; r++)
            {
                for(int c = 0; c < DIM; c++)
                {
                    if(arr[r][c] == 1 && (r == i || c == j))
                    {
                        sum++;
                    }
                }
            }
            if(sum >= 3)
            {
                arr[i][j] = 2;
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

    return 0;
}