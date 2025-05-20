//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main()
{
    int **arr = NULL;
    int i, j, k, x, y, z;
    int num_percolation = 0;

    arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Percolation Matrix Initialization
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Randomly Assign Percolation Sites
    for (k = 0; k < 10; k++)
    {
        x = rand() % MAX_SIZE;
        y = rand() % MAX_SIZE;
        arr[x][y] = 1;
    }

    // Percolation Algorithm
    for (z = 0; z < MAX_SIZE; z++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                if (arr[i][j] == 1)
                {
                    num_percolation++;
                    arr[i][j] = 2;
                }
                else
                {
                    int count = 0;
                    for (x = -1; x <= 1; x++)
                    {
                        for (y = -1; y <= 1; y++)
                        {
                            if (arr[i + x][j + y] == 2)
                            {
                                count++;
                            }
                        }
                    }
                    if (count > 0)
                    {
                        arr[i][j] = 2;
                        num_percolation++;
                    }
                }
            }
        }
    }

    // Print Percolation Sites
    printf("Percolation Sites:\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Number of Percolation Sites: %d\n", num_percolation);

    free(arr);

    return 0;
}