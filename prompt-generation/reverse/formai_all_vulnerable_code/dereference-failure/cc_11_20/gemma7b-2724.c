//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 20

int main()
{
    int **arr = NULL;
    int i, j, k, r, c;
    int **adj = NULL;
    int num_cells = MAX * MAX;

    arr = (int *)malloc(num_cells * sizeof(int));
    adj = (int **)malloc(num_cells * sizeof(int *));
    for (i = 0; i < num_cells; i++)
    {
        adj[i] = (int *)malloc(num_cells * sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < num_cells; i++)
    {
        arr[i] = rand() % 2;
    }

    for (i = 0; i < num_cells; i++)
    {
        for (j = 0; j < num_cells; j++)
        {
            adj[i][j] = 0;
            if (i - 1 >= 0 && arr[i - 1][j] == 1)
            {
                adj[i][j] = 1;
            }
            if (j - 1 >= 0 && arr[i][j - 1] == 1)
            {
                adj[i][j] = 1;
            }
            if (i + 1 < num_cells && arr[i + 1][j] == 1)
            {
                adj[i][j] = 1;
            }
            if (j + 1 < num_cells && arr[i][j + 1] == 1)
            {
                adj[i][j] = 1;
            }
        }
    }

    for (i = 0; i < num_cells; i++)
    {
        for (j = 0; j < num_cells; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(adj);

    return 0;
}