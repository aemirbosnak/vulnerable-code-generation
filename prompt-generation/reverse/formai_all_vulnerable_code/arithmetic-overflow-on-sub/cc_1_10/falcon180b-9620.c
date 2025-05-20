//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int n, m;
Edge edges[MAX_EDGES];
int dist[MAX_NODES];
int parent[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INT_MAX;
        u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int edge_dist = edges[u * n + v].w;

                if (dist[u] + edge_dist < dist[v]) {
                    dist[v] = dist[u] + edge_dist;
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int end) {
    int u = end;

    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
}

int main() {
    int i, u, v, w;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v w):\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {.u = u,.v = v,.w = w};
    }

    int start, end;

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter end node: ");
    scanf("%d", &end);

    dijkstra(start);

    printf("Shortest path from %d to %d:\n", start, end);
    print_path(end);

    return 0;
}