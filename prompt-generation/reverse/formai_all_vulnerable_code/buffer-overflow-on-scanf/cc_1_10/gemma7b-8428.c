//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void findCentroid(int **arr, int n)
{
    int i, j, x = 0, y = 0, z = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                x += arr[i][j];
                y += arr[i][j];
                z += arr[i][j];
            }
        }
    }

    x /= (n * (n - 1));
    y /= (n * (n - 1));
    z /= (n * (n - 1));

    printf("Centroid coordinates: (%d, %d, %d)\n", x, y, z);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *) + n * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n);

    free(arr);

    return 0;
}