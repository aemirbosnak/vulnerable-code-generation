//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, k, l, n, m, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of branches: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter the source node of branch %d: ", i + 1);
        scanf("%d", &k);

        printf("Enter the destination node of branch %d: ", i + 1);
        scanf("%d", &l);

        a[k] = l;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (a[i] == j)
            {
                b[i] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            printf("Node %d is isolated.\n", i);
        }
    }

    return 0;
}