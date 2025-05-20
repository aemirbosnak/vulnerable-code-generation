//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

int edges[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];

int dijkstra(int start, int end, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j; // find the unvisited vertex with the smallest distance
            }
        }
        if (dist[u] == INF) {
            break; // all remaining vertices are inaccessible
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (edges[u][v] != INF) { // if there's an edge between u and v
                int alt = dist[u] + edges[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt; // update the distance to v
                }
            }
        }
    }
    return dist[end];
}

int main() {
    int n, m, start, end;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);
    printf("Enter the edges in the format 'u v w' (u, v are nodes and w is weight):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[u][v] = w;
        edges[v][u] = w;
    }
    printf("Enter the start and end nodes: ");
    scanf("%d%d", &start, &end);
    int shortest = dijkstra(start, end, n);
    printf("Shortest path between %d and %d is %d\n", start, end, shortest);
    return 0;
}