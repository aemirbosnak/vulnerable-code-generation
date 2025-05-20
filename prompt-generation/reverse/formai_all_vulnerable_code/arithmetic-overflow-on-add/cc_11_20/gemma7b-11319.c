//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, b, a[1000], c[1000], d[1000], e[1000];

    scanf("Enter the number of test cases:", &n);

    for (i = 0; i < n; i++)
    {
        scanf("Enter the number of vertices:", &b);

        for (j = 0; j < b; j++)
        {
            scanf("Enter the vertex number:", &a[j]);
        }

        for (k = 0; k < b; k++)
        {
            scanf("Enter the edge number:", &c[k]);
        }

        for (l = 0; l < b; l++)
        {
            scanf("Enter the distance:", &d[l]);
        }

        for (m = 0; m < b; m++)
        {
            scanf("Enter the cost:", &e[m]);
        }

        // Calculate the minimum cost
        for (k = 0; k < b; k++)
        {
            for (l = 0; l < b; l++)
            {
                if (c[k] == c[l])
                {
                    if (d[k] + e[l] < d[l])
                    {
                        d[l] = d[k] + e[l];
                    }
                }
            }
        }

        // Print the minimum cost
        for (i = 0; i < b; i++)
        {
            printf("The minimum cost to vertex %d is %d.\n", a[i], d[i]);
        }
    }

    return 0;
}