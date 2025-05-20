//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, m, t, graph[MAX], color[MAX];

    scanf("Enter number of test cases: ", &t);

    for (k = 0; k < t; k++)
    {
        scanf("Enter number of vertices: ", &n);

        for (i = 0; i < n; i++)
        {
            graph[i] = 0;
        }

        scanf("Enter number of edges: ", &m);

        for (i = 0; i < m; i++)
        {
            scanf("Enter edge: ", &l);
            scanf("Enter edge: ", &j);
            graph[l] = j;
        }

        color[0] = 1;
        color[1] = 2;

        for (i = 2; i < n; i++)
        {
            color[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i] == j)
                {
                    if (color[i] == color[j])
                    {
                        color[i] = 0;
                    }
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            if (color[i] != 0)
            {
                printf("Vertex %d has a color of %d.\n", i + 1, color[i]);
            }
        }
    }

    return 0;
}