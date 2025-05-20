//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void distance(int **arr, int i, int j)
{
    int d = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]) + abs(arr[i][2] - arr[j][2]);
    arr[i][3] = d;
}

void cluster(int **arr, int n)
{
    int i, j, k, dmin, min, centroid[MAX], ctr = 0;

    for (i = 0; i < n; i++)
    {
        centroid[i] = MAX;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            distance(arr, i, j);
        }
    }

    for (i = 0; i < n; i++)
    {
        min = MAX;
        for (j = 0; j < n; j++)
        {
            if (arr[i][3] < min)
            {
                min = arr[i][3];
                centroid[i] = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Point %d is clustered with point %d\n", arr[i][0], centroid[i]);
    }
}

int main()
{
    int n, i, j;
    int **arr;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int *) + n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(4 * sizeof(int));
    }

    printf("Enter the coordinates of each point (x, y, z): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", arr[i][0], arr[i][1], arr[i][2]);
    }

    cluster(arr, n);

    return 0;
}