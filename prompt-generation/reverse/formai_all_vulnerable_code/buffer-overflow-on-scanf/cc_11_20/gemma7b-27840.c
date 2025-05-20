//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, m, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX], g[MAX];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices: ");
        scanf("%d", &m);

        printf("Enter the adjacency list: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the query: ");
        scanf("%d", &k);

        for (l = 0; l < k; l++)
        {
            scanf("%d", &b[l]);
        }

        for (j = 0; j < m; j++)
        {
            c[j] = 0;
        }

        for (l = 0; l < k; l++)
        {
            for (j = 0; j < m; j++)
            {
                if (a[j] == b[l])
                {
                    c[j] = 1;
                }
            }
        }

        for (j = 0; j < m; j++)
        {
            if (c[j] == 1)
            {
                d[j] = 1;
            }
        }

        printf("The vertices connected to each vertex in the query are: ");
        for (j = 0; j < m; j++)
        {
            printf("%d ", d[j]);
        }

        printf("\n");
    }

    return 0;
}