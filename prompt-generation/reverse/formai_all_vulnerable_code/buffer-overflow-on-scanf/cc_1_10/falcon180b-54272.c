//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 100
#define INF 9999

int V, E;
int adj_mat[MAX_V][MAX_V];
int dist[MAX_V];
bool visited[MAX_V];

void dijkstra(int start) {
    int u, v, i, min_dist;
    for (u = 0; u < V; u++) {
        dist[u] = INF;
        visited[u] = false;
    }
    dist[start] = 0;
    for (i = 0; i < V-1; i++) {
        min_dist = INF;
        for (u = 0; u < V; u++) {
            if (!visited[u] && dist[u] < min_dist) {
                min_dist = dist[u];
                v = u;
            }
        }
        visited[v] = true;
        for (u = 0; u < V; u++) {
            if (!visited[u] && adj_mat[v][u] > 0 && dist[v] + adj_mat[v][u] < dist[u]) {
                dist[u] = dist[v] + adj_mat[v][u];
            }
        }
    }
}

int main() {
    int u, v, w, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges with their weights (u v w):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj_mat[u][v] = w;
        adj_mat[v][u] = w;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    dijkstra(start);
    printf("Vertex\tDistance\n");
    for (u = 0; u < V; u++) {
        printf("%d\t%d\n", u, dist[u]);
    }
    return 0;
}