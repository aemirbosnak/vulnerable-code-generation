//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, graph[MAX][MAX], color[MAX], paranoia = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    graph[MAX][MAX] = 0;
    color[MAX] = 0;

    for (i = 0; i < k; i++)
    {
        scanf("Enter the source node: ");
        scanf("Enter the destination node: ");
        graph[i][0] = 1;
        graph[i][1] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                color[i] = color[j] ^ 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i + 1, color[i]);
    }

    if (paranoia)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1 && color[i] == color[j])
                {
                    printf("DANGER: Node %d and Node %d have the same color!\n", i + 1, j + 1);
                }
            }
        }
    }

    return 0;
}