//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **arr = NULL;
    int i, j, k, r, c, x, y;
    int **percolation_array = NULL;

    arr = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    percolation_array = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        percolation_array[i] = (int *)malloc(MAX * sizeof(int));
    }

    r = MAX;
    c = MAX;

    // Initializing the Percolation Array
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            percolation_array[i][j] = 0;
        }
    }

    // Placing the Obstacles
    percolation_array[2][2] = 1;
    percolation_array[3][2] = 1;

    // Running the Percolation Algorithm
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (percolation_array[i][j] == 0)
                {
                    x = i - 1;
                    y = j - 1;

                    if (x >= 0 && percolation_array[x][y] == 1)
                    {
                        percolation_array[i][j] = 1;
                    }

                    x = i + 1;
                    y = j - 1;

                    if (x < r && percolation_array[x][y] == 1)
                    {
                        percolation_array[i][j] = 1;
                    }

                    x = i - 1;
                    y = j + 1;

                    if (x >= 0 && percolation_array[x][y] == 1)
                    {
                        percolation_array[i][j] = 1;
                    }

                    x = i + 1;
                    y = j + 1;

                    if (x < r && percolation_array[x][y] == 1)
                    {
                        percolation_array[i][j] = 1;
                    }
                }
            }
        }
    }

    // Printing the Percolation Array
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", percolation_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}