//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, k, n, m, graph[MAX][MAX], distance[MAX], parent[MAX], visited[MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph[n][n] = 1;

    for (i = 0; i < m; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &k);

        printf("Enter the destination node: ");
        scanf("%d", &j);

        graph[k][j] = 1;
    }

    distance[0] = 0;
    parent[0] = -1;

    for (i = 1; i < n; i++)
    {
        distance[i] = MAX;
        parent[i] = -1;
    }

    distance[0] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && distance[i] + 1 < distance[j])
            {
                distance[j] = distance[i] + 1;
                parent[j] = i;
            }
        }
    }

    printf("The shortest path is: ");

    for (i = 1; i < n; i++)
    {
        printf("%d ", parent[i]);
    }

    printf("\nThe distance is: ");

    for (i = 1; i < n; i++)
    {
        printf("%d ", distance[i]);
    }

    return 0;
}