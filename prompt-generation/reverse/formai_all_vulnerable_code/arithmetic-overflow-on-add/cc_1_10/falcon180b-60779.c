//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define V 4

int adj_mat[V][V] = {
    {0, 2, 0, 0},
    {INF, 0, 1, INF},
    {0, INF, 0, 2},
    {INF, INF, INF, 0}
};

void dijkstra(int start_vertex) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start_vertex] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = -1, min_dist = INF;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj_mat[u][v] && dist[u]!= INF &&
                dist[u] + adj_mat[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_mat[u][v];
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    dijkstra(0);
    return 0;
}