//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min_dist, cluster_size = 0, **distances = NULL;

    distances = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        distances[i] = MAX;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            l = 0;
            for (d = 0; d < n; d++)
            {
                if (i != d)
                {
                    min_dist = abs(arr[i] - arr[d]) + abs(arr[i] - arr[j]);
                    if (min_dist < distances[j])
                        distances[j] = min_dist;
                }
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        cluster_size = 0;
        for (j = 0; j < n; j++)
        {
            if (distances[j] == distances[i])
                cluster_size++;
        }
        printf("Cluster %d has %d members.\n", i + 1, cluster_size);
    }

    free(distances);
}

int main()
{
    int n, k;
    int **arr;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the data points: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cluster(arr, n, k);

    free(arr);

    return 0;
}