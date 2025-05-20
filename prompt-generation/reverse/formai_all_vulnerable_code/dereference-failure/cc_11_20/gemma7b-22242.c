//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 256

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the array
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation simulation
    int x = size / 2;
    int y = size / 2;
    arr[x][y] = 1;

    int iterations = 0;
    while(!arr[0][0] && iterations < 1000)
    {
        iterations++;

        // Iterate over the array
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(arr[i][j] == 1)
                {
                    // Check the neighbors
                    if(arr[i-1][j] == 0 && rand() % 2 == 0)
                        arr[i-1][j] = 1;
                    if(arr[i+1][j] == 0 && rand() % 2 == 0)
                        arr[i+1][j] = 1;
                    if(arr[i][j-1] == 0 && rand() % 2 == 0)
                        arr[i][j-1] = 1;
                    if(arr[i][j+1] == 0 && rand() % 2 == 0)
                        arr[i][j+1] = 1;
                }
            }
        }
    }

    // Print the result
    printf("Number of iterations: %d\n", iterations);
    printf("Percolation successful: %d\n", arr[0][0]);

    // Free the memory
    for(int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}