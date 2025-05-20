//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int i, j, k, n, m, **graph, **visited, **distance;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    distance = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        graph[i] = -1;
        visited[i] = 0;
        distance[i] = MAX;
    }

    for (i = 0; i < m; i++)
    {
        int u, v;
        printf("Enter the two nodes connected by edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u] = v;
    }

    distance[0] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i] == j)
            {
                distance[j] = distance[i] + 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Node %d is at a distance of %d from node 0.\n", i + 1, distance[i]);
    }

    free(graph);
    free(visited);
    free(distance);

    return 0;
}