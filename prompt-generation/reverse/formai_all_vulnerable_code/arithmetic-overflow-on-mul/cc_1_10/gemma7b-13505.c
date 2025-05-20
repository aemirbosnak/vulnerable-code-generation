//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int main()
{
    int i, j, k, n, m, **arr, **ptr, percolates = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    arr = (int *)malloc(n * m * sizeof(int));
    ptr = (int *)malloc(n * m * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i * m + j] = rand() % 2;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            ptr[i * m + j] = arr[i * m + j] + 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (ptr[i * m + j] >= MAX)
            {
                percolates++;
            }
        }
    }

    printf("The number of percolations is: %d", percolates);

    free(arr);
    free(ptr);

    return 0;
}