//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n, i, j, k;
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    n = rand() % MAX;
    arr[n][n] = 1;

    for (k = 0; k < MAX; k++)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] = 2;
                    if (i - 1 >= 0)
                        arr[i - 1][j] = 2;
                    if (i + 1 < MAX)
                        arr[i + 1][j] = 2;
                    if (j - 1 >= 0)
                        arr[i][j - 1] = 2;
                    if (j + 1 < MAX)
                        arr[i][j + 1] = 2;
                }
            }
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}