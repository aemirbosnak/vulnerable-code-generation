//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    int i, j, k, l, n, m, **a, **b, centroids[MAX], **distance;

    printf("Enter the number of clusters:");
    scanf("%d", &n);

    printf("Enter the number of data points:");
    scanf("%d", &m);

    a = (int *)malloc(m * sizeof(int));
    b = (int *)malloc(m * sizeof(int));
    distance = (int *)malloc(m * n * sizeof(int));

    // Getting data points
    printf("Enter the data points:");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    // Calculating distances
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            distance[i][j] = abs(a[i] - centroids[j]);
        }
    }

    // Assigning data points to clusters
    for (i = 0; i < m; i++)
    {
        k = 0;
        for (j = 0; j < n; j++)
        {
            if (distance[i][j] < distance[i][k])
            {
                k = j;
            }
        }
        b[i] = k + 1;
    }

    // Printing cluster memberships
    printf("The cluster memberships are:");
    for (i = 0; i < m; i++)
    {
        printf("Data point %d belongs to cluster %d\n", a[i], b[i]);
    }

    free(a);
    free(b);
    free(distance);

    return 0;
}