//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];

void dijkstra(int src, int dest) {
    int u, v;

    for (u = 0; u < V; u++) {
        dist[src][u] = 0;
        parent[src][u] = -1;
    }

    dist[src][src] = 0;

    for (int i = 1; i < V; i++) {
        int min_dist = INF, u = -1;

        for (int j = 0; j < V; j++) {
            if (dist[src][j] <= min_dist && parent[src][j]!= -1) {
                min_dist = dist[src][j];
                u = j;
            }
        }

        for (int v = 0; v < V; v++) {
            if (dist[src][v] > dist[src][u] + dist[u][v]) {
                dist[src][v] = dist[src][u] + dist[u][v];
                parent[src][v] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");

    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[src][i]);
    }
}

int main() {
    int graph[V][V] = { { 0, 4, INF, 0, 0, 0, 0, 8, 0 },
                        { INF, 0, 8, INF, 0, 0, 0, 11, 0 },
                        { INF, INF, 0, 0, 0, 7, INF, INF, 2 },
                        { 0, INF, INF, 0, 9, 14, 0, INF, 0 },
                        { 0, 0, 7, 14, 0, INF, 4, INF, 0 },
                        { INF, 0, INF, 9, 4, 0, INF, 2, 0 },
                        { 0, 11, INF, INF, 0, 2, 0, 1, 6 },
                        { INF, INF, 2, INF, INF, INF, 1, 0, 7 },
                        { 8, INF, INF, 0, 0, INF, 6, 7, 0 } };

    int source, destination;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}