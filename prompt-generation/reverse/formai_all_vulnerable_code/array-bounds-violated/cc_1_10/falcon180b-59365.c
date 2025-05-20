//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];

void dijkstra(int graph[V][V], int src) {
    int u, v, i, min, k;
    int visited[V] = {0};
    int parent[V] = {-1};

    for (u = 0; u < V; u++) {
        dist[src][u] = graph[src][u];
        parent[u] = -1;
    }

    dist[src][src] = 0;

    for (k = 0; k < V - 1; k++) {
        min = INF;
        u = -1;

        for (i = 0; i < V; i++) {
            if (visited[i] == 0 && dist[src][i] <= min) {
                min = dist[src][i];
                u = i;
            }
        }

        visited[u] = 1;

        for (v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 &&
                dist[src][u]!= INF &&
                dist[src][u] + graph[u][v] < dist[src][v]) {
                dist[src][v] = dist[src][u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[src][i]);
    }
}

int main() {
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}