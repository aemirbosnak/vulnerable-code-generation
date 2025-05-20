//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, r, t, x, y, z;
    char **a, **b, **c;

    a = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(m * sizeof(char));
    }

    b = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        b[i] = (char *)malloc(m * sizeof(char));
    }

    c = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        c[i] = (char *)malloc(m * sizeof(char));
    }

    t = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c ", &a[i][j]);
            if (a[i][j] == 'T')
            {
                t++;
            }
        }
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c ", &b[i][j]);
            if (b[i][j] == 'K')
            {
                k++;
            }
        }
    }

    l = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c ", &c[i][j]);
            if (c[i][j] == 'L')
            {
                l++;
            }
        }
    }

    r = t + k - l;
    printf("The number of rooms is: %d\n", r);

    return 0;
}