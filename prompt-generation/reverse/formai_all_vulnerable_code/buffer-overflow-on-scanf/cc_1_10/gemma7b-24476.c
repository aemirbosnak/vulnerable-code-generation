//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the values of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter the total capacity of the bag: ");
    scanf("%d", &c[0]);

    for (i = 0; i < n; i++)
    {
        d[i] = a[i] * b[i];
    }

    for (i = 0; i < n; i++)
    {
        e[i] = d[i] / c[0];
    }

    k = 0;
    l = 0;
    m = 0;
    for (i = 0; i < n; i++)
    {
        if (e[i] > k)
        {
            k = e[i];
            l = i;
        }
    }

    printf("The maximum value that can be obtained is: %d", k);

    printf("The item that gives the maximum value is: %d", l);

    return;
}