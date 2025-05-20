//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];

void dijkstra(int graph[V][V], int src) {
    int u, v, i, j, min_dist, dist_u_v;

    for (u = 0; u < V; u++) {
        dist[u][src] = 0;
        parent[u][src] = -1;
    }

    for (i = 1; i < V; i++) {
        for (u = 0; u < V; u++) {
            for (v = 0; v < V; v++) {
                if (graph[u][v] && dist[u][v]!= INF && dist[u][v] + graph[v][i] < dist[u][i]) {
                    dist[u][i] = dist[u][v] + graph[v][i];
                    parent[u][i] = v;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");

    for (i = 0; i < V; i++) {
        if (i!= src) {
            printf("%d \t %d\n", i, dist[src][i]);
        }
    }
}

int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int src;

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}