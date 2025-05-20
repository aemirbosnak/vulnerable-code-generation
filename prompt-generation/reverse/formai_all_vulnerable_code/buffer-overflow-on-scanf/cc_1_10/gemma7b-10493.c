//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min_dist, cluster_num = 0;
    int **distance = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            distance[i][j] = abs(arr[i] - arr[j]);
        }
    }

    for (l = 0; l < k; l++)
    {
        min_dist = MAX;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (distance[i][j] < min_dist)
                {
                    min_dist = distance[i][j];
                    cluster_num = i;
                }
            }
        }

        printf("Cluster %d: ", cluster_num + 1);
        for (d = 0; d < n; d++)
        {
            if (distance[cluster_num][d] <= min_dist)
            {
                printf("%d ", arr[d]);
            }
        }
        printf("\n");
    }

    free(distance);
}

int main()
{
    int n, k;
    scanf("Enter the number of data points: ", &n);
    scanf("Enter the number of clusters: ", &k);

    int **arr = (int *)malloc(n * sizeof(int));
    printf("Enter the data points: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    cluster(arr, n, k);

    return 0;
}