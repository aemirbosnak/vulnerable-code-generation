//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min, centroid[k], ctr[k], cluster[n];
    double dist, sum, sqsum;

    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
        ctr[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        cluster[i] = -1;
    }

    for (l = 0; l < k; l++)
    {
        for (i = 0; i < n; i++)
        {
            dist = 0;
            for (j = 0; j < k; j++)
            {
                if (cluster[i] == j)
                    continue;

                for (d = 0; d < MAX; d++)
                {
                    if (arr[i][d] - centroid[j] == 0)
                        dist = dist + 1;
                }

                if (dist < min)
                    min = dist;
            }

            cluster[i] = min;
            centroid[min] += arr[i][l];
            ctr[min]++;
            min = MAX;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to cluster %d\n", arr[i][0], cluster[i]);
    }
}

int main()
{
    int **arr, n, k;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the number of clusters:");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(MAX * sizeof(int));

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < MAX; j++)
            scanf("%d", &arr[i][j]);

    cluster(arr, n, k);

    return 0;
}