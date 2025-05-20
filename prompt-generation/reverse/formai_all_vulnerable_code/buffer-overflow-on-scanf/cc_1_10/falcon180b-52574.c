//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF  INT_MAX
#define V 4

int graph[V][V];
int dist[V];
int parent[V];

void dijkstra(int spt, int dest)
{
    int i, u, v;
    int min_dist = INF, min_u;

    for (i = 0; i < V; i++)
        dist[i] = graph[spt][i], parent[i] = -1;

    dist[spt] = 0;

    for (i = 0; i < V - 1; i++) {
        min_dist = INF;
        min_u = -1;

        for (u = 0; u < V; u++) {
            if (dist[u] <= min_dist && parent[u] == -1) {
                min_dist = dist[u];
                min_u = u;
            }
        }

        for (v = 0; v < V; v++) {
            if ((graph[min_u][v]!= INF) && ((dist[min_u] + graph[min_u][v]) < dist[v])) {
                dist[v] = dist[min_u] + graph[min_u][v];
                parent[v] = min_u;
            }
        }
    }

    printf("\nVertex \t Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = { { 0, 4, INF, 0 },
                        { INF, 0, 8, 0 },
                        { INF, INF, 0, 2 },
                        { 0, INF, INF, 0 } };
    int source, dest;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(source, dest);

    return 0;
}