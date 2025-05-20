//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 5

int graph[V][V] = {
    {0, 2, INF, 1},
    {INF, 0, 1, INF},
    {INF, INF, 0, 2},
    {INF, INF, INF, 0}
};

void dijkstra(int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        int u = -1, min_dist = INF;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}