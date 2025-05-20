//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
    int **arr = NULL;
    int i, j, k, seed;

    // Allocate memory for the array
    arr = (int **)malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array randomly
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    // Percolation algorithm
    for(k = 0; k < DIM; k++)
    {
        for(i = 0; i < DIM; i++)
        {
            for(j = 0; j < DIM; j++)
            {
                if(arr[i][j] == 1 && (arr[i-1][j] == 1 || arr[i+1][j] == 1 || arr[i][j-1] == 1 || arr[i][j+1] == 1))
                {
                    arr[i][j] = 2;
                }
            }
        }
    }

    // Print the result
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < DIM; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}