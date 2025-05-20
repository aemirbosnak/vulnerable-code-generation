//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, min_dist, cluster_no, **distances, **centers;

    distances = (int *)malloc(n * sizeof(int));
    centers = (int *)malloc(k * sizeof(int));

    for (i = 0; i < n; i++)
    {
        distances[i] = MAX;
    }

    for (i = 0; i < k; i++)
    {
        centers[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = abs(arr[i] - centers[j]);
            if (distances[i] > d)
            {
                distances[i] = d;
                cluster_no = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to Cluster %d\n", arr[i], cluster_no);
    }

    free(distances);
    free(centers);
}

int main()
{
    int n, k, **arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the number of clusters:");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cluster(arr, n, k);

    return 0;
}