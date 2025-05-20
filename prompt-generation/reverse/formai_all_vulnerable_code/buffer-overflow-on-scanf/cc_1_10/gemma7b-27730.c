//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[1000], b[1000], c[1000];

    printf("Enter the number of test cases:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices:");
        scanf("%d", &l);

        printf("Enter the adjacency list:");
        for (j = 0; j < l; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the number of edges:");
        scanf("%d", &m);

        printf("Enter the edge list:");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &b[j]);
        }

        k = 0;
        for (j = 0; j < l; j++)
        {
            for (l = 0; l < m; l++)
            {
                if (a[j] == b[l])
                {
                    c[k] = 1;
                    k++;
                }
            }
        }

        for (i = 0; i < l; i++)
        {
            printf("The degree of vertex %d is %d\n", i, c[i]);
        }
    }

    return 0;
}