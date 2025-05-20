//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, c, ctr = 0, **distance = (int *)malloc(n * n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            distance[i][j] = abs(arr[i] - arr[j]);
        }
    }

    for (c = 0; c < k; c++)
    {
        int minDistance = MAX;
        int minIndex = -1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (distance[i][j] < minDistance)
                {
                    minDistance = distance[i][j];
                    minIndex = i;
                }
            }
        }

        ctr++;
        printf("Cluster %d: ", ctr);
        printf("Element %d: ", minIndex);
        printf("Distance: %d\n", minDistance);

        distance[minIndex][minIndex] = MAX;
    }

    free(distance);
}

int main()
{
    int n, k;
    scanf("Enter the number of elements: ", &n);
    scanf("Enter the number of clusters: ", &k);

    int **arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    cluster(arr, n, k);

    free(arr);

    return 0;
}