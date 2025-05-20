//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void cluster(int **arr, int n, int k)
{
    int i, j, d, c, centroid[k], ctr[n];

    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        ctr[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = 0;
            for (c = 0; c < MAX; c++)
            {
                if (arr[i][c] - centroid[j] == 0)
                {
                    d++;
                }
            }
            if (ctr[i] == -1 || d > ctr[i])
            {
                ctr[i] = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to Cluster %d\n", arr[i][0], ctr[i] + 1);
    }
}

int main()
{
    int **arr = NULL;
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
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

    return 0;
}