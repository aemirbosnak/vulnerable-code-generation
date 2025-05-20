//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int n, m, i, j, k, graph[MAX][MAX], distance[MAX], parent[MAX];
    char side[MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph[n][n] = 1;
    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
        distance[i] = MAX;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &k, &j);
        graph[k][j] = 1;
    }

    distance[0] = 0;
    parent[0] = 0;

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
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", parent[i]);
    }

    printf("\nThe distance is: %d", distance[n - 1]);

    return 0;
}