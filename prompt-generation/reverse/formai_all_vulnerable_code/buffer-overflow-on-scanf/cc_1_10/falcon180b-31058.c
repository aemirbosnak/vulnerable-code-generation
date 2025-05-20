//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define V 4
#define E 6

int graph[V][V] = { { 0, 2, 0, 0 },
                    { 0, 0, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 1 } };

int dist[V];
int visited[V];
int parent[V];

void dijkstra(int src) {
    int u, v, i, min_dist;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (i = 0; i < V - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
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