//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int n, m, i, j, k, l, graph[MAX][MAX], color[MAX], max_color = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph[n][m] = (int *)malloc(sizeof(int) * (n * m));

    printf("Enter the adjacency list: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &graph[0][i], &graph[1][i]);
    }

    color[n] = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n; l++)
        {
            if (graph[k][l] && color[k] == color[l])
            {
                printf("Error: nodes %d and %d have the same color.", k, l);
                return 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        color[i] = rand() % max_color + 1;
    }

    printf("The graph coloring is:\n");
    for (i = 0; i < n; i++)
    {
        printf("Node %d has color %d.\n", i, color[i]);
    }

    return 0;
}