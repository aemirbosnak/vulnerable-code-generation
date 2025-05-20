//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void findCentroid(int **arr, int n)
{
    int i, j, x = 0, y = 0, totalArea = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                x += arr[i][j] * (i + 1);
                y += arr[i][j] * (j + 1);
                totalArea += arr[i][j];
            }
        }
    }

    printf("Centroid coordinates: (%d, %d)\n", x / totalArea, y / totalArea);
}

int main()
{
    int n, i, j, **arr = NULL;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the matrix elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n);

    return 0;
}