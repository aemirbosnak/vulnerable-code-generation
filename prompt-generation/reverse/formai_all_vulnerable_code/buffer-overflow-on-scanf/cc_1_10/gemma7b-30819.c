//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, n, k, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

    n = 0;
    a[n] = 0;
    b[n] = 0;
    c[n] = 0;
    d[n] = 0;
    e[n] = 0;

    printf("Enter the number of items: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &a[i]);

        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < k; i++)
    {
        c[i] = a[i] * b[i];
    }

    for (i = 0; i < k; i++)
    {
        d[i] = c[i] / MAX;
    }

    for (i = 0; i < k; i++)
    {
        e[i] = d[i] * MAX;
    }

    for (i = 0; i < k; i++)
    {
        printf("The maximum value that can be obtained from item %d is: %d\n", i + 1, e[i]);
    }

    return 0;
}