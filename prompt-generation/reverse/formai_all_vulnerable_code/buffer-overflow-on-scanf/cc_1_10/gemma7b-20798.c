//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: scalable
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
            if (arr[i][j] != 0)
            {
                x += i;
                y += j;
                z++;
            }
        }
    }

    printf("Centroid coordinates: (%d, %d)\n", x / z, y / z);
}

int main()
{
    int **arr = NULL;
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the matrix elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n);

    return 0;
}