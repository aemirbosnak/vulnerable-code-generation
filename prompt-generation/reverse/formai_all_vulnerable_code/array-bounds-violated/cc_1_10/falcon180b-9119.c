//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGE];
int n, m, adj[MAX_VERTEX][MAX_VERTEX];

void dijkstra(int start) {
    int i, u, v, min_dist, dist[MAX_VERTEX];

    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (adj[u][v]!= INF && dist[u]!= INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    printf("Vertex\t\tDistance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u, v, w):\n");

    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);

        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;

        adj[u][v] = w;
        adj[v][u] = w;
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}