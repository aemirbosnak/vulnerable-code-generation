//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, centroid[k], ctr[n], clust[n];
    float dist;

    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        ctr[i] = -1;
    }

    for (l = 0; l < n; l++)
    {
        for (i = 0; i < k; i++)
        {
            dist = 0.0;
            for (j = 0; j < k; j++)
            {
                if (i == j)
                {
                    continue;
                }
                for (d = 0; d < MAX; d++)
                {
                    if (arr[l][d] != arr[i][d] && arr[l][d] != arr[j][d])
                    {
                        dist += abs(arr[l][d] - arr[i][d]) * abs(arr[l][d] - arr[j][d]);
                    }
                }
            }
            centroid[i] += dist;
        }
    }

    for (i = 0; i < n; i++)
    {
        int min_dist = MAX;
        for (j = 0; j < k; j++)
        {
            if (centroid[j] - dist < min_dist)
            {
                min_dist = centroid[j] - dist;
                clust[i] = j;
            }
        }
    }

    printf("Cluster memberships:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", clust[i]);
    }
    printf("\n");
}

int main()
{
    int n, k, **arr;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the data points: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    cluster(arr, n, k);

    return 0;
}