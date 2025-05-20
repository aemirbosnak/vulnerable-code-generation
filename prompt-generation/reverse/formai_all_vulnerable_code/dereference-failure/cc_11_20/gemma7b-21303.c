//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
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

    int percolate = 0;
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            int count = 0;
            if(arr[i][j] == 1)
            {
                // Check the four neighbors
                if(i > 0 && arr[i-1][j] == 1) count++;
                if(i < DIM-1 && arr[i+1][j] == 1) count++;
                if(j > 0 && arr[i][j-1] == 1) count++;
                if(j < DIM-1 && arr[i][j+1] == 1) count++;

                if(count >= 3)
                {
                    arr[i][j] = 2;
                    percolate++;
                }
            }
        }
    }

    printf("Number of percolations: %d", percolate);

    free(arr);

    return 0;
}