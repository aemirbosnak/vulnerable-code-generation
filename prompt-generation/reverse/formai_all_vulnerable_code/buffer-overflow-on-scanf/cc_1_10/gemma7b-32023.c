//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    int n, i, j, k, d, cluster_num, **X, **C;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    X = (int *)malloc(n * sizeof(int));
    C = (int *)malloc(n * sizeof(int));

    printf("Enter the data points: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &X[i]);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &cluster_num);

    k = 0;
    for (i = 0; i < n; i++)
    {
        C[i] = -1;
    }

    for (i = 0; i < cluster_num; i++)
    {
        for (j = 0; j < n; j++)
        {
            d = abs(X[j] - X[k]);
            if (d < 5)
            {
                C[j] = i + 1;
            }
        }
        k++;
    }

    printf("The clusters are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", C[i]);
    }

    free(X);
    free(C);

    return 0;
}