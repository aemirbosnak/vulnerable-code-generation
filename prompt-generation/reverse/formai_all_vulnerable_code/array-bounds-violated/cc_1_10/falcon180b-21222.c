//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];

void dijkstra(int src, int dest)
{
    int u, v, i, j, min_dist, k;

    for (i = 0; i < V; i++)
        dist[src][i] = dist[i][src] = INF, parent[src][i] = parent[i][src] = -1;

    dist[src][src] = 0;

    for (k = 0; k < V - 1; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = k;
                }
            }
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, dist[src][i]);
    }
}

int main()
{
    int graph[V][V] = { { 0, 4, INF, 0, 0, 0, 0, 8, 0 },
                        { INF, 0, 8, INF, 0, 0, 0, 11, 0 },
                        { INF, 8, 0, INF, 7, 0, 4, 0, 2 },
                        { 0, INF, INF, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 7, 9, 0, INF, 2, 0, 0 },
                        { 0, 0, 0, 14, INF, 0, 0, 1, 6 },
                        { INF, 0, 4, 0, 2, INF, 0, 6, 7 },
                        { 8, INF, 0, 0, 0, 1, 6, 0, 9 },
                        { 0, 11, 0, 0, 0, 7, 9, 9, 0 } };

    int source, dest;

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    printf("\nEnter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(source, dest);

    return 0;
}