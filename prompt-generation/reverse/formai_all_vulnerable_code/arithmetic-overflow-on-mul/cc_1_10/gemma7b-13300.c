//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    int n, i, j, k, d, **a, **c, **b, **p, centroid[MAX];

    printf("Enter the number of clusters:");
    scanf("%d", &n);

    a = (int *)malloc(n * MAX);
    c = (int *)malloc(n * MAX);
    b = (int *)malloc(n * MAX);
    p = (int *)malloc(n * MAX);

    printf("Enter the number of data points:");
    scanf("%d", &d);

    for (i = 0; i < d; i++)
    {
        printf("Enter the data point:");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        centroid[i] = -1;
    }

    for (k = 0; k < d; k++)
    {
        int min_dist = MAX;
        for (i = 0; i < n; i++)
        {
            int dist = abs(a[k] - centroid[i]);
            if (dist < min_dist)
            {
                min_dist = dist;
                c[k] = i;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("The data points assigned to cluster %d are:", i + 1);
        for (j = 0; j < d; j++)
        {
            if (c[j] == i)
            {
                printf(" %d ", a[j]);
            }
        }
        printf("\n");
    }

    free(a);
    free(c);
    free(b);
    free(p);

    return 0;
}