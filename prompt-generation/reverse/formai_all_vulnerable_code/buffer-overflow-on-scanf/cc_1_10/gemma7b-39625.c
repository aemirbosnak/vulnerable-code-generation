//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, **c, ctr = 0;
    float **dist, **cent;

    dist = (float **)malloc(n * sizeof(float *));
    cent = (float **)malloc(k * sizeof(float *));

    c = (int *)malloc(k * sizeof(int));

    for (i = 0; i < n; i++)
    {
        dist[i] = (float *)malloc(k * sizeof(float));
    }

    for (i = 0; i < k; i++)
    {
        cent[i] = (float *)malloc(n * sizeof(float));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            dist[i][j] = 1000000;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            for (l = 0; l < k; l++)
            {
                if (j == l)
                {
                    dist[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        int min = 1000000;
        for (j = 0; j < k; j++)
        {
            if (dist[i][j] < min)
            {
                min = dist[i][j];
                c[i] = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to cluster %d\n", arr[i], c[i]);
    }

    free(dist);
    free(cent);
    free(c);
}

int main()
{
    int **arr = (int **)malloc(MAX * sizeof(int *));
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cluster(arr, n, k);

    free(arr);

    return 0;
}