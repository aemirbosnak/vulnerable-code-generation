//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, n, m, k, a[MAX], b[MAX], c[MAX], d[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the number of buyers: ");
    scanf("%d", &m);

    printf("Enter the demand of each buyer: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the supply of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[k] = a[j] * b[i];
            k++;
        }
    }

    printf("The total revenue is: ");
    d[0] = 0;
    for (i = 0; i < n; i++)
    {
        d[i + 1] = d[i] + b[i];
    }
    for (i = 0; i < m; i++)
    {
        printf("%d ", d[a[i]] - c[a[i]] + a[i]);
    }

    return 0;
}