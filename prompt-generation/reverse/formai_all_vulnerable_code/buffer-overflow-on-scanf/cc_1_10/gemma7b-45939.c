//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX], d[MAX];

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
        d[i] = b[i] / a[i];
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        if (k + d[i] <= c[0])
        {
            k += d[i];
            c[0] -= d[i] * a[i];
        }
        else
        {
            c[0] = c[0] - d[i] * a[i];
        }
    }

    printf("The total value of items that can be carried is: %d", c[0]);

    return;
}