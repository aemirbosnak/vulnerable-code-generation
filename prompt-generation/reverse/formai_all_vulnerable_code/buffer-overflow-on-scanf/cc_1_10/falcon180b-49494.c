//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int adj[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        for (j = 0; j < MAX_NODES - 1; j++) {
            if (dist[j] > dist[u] + edges[u].w) {
                dist[j] = dist[u] + edges[u].w;
            }
        }
    }
}

int main() {
    int i, j, u, v, w, n, m, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges in the format u v w:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        adj[u][v] = w;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("The shortest path from node %d:\n", start);
    for (i = 0; i < n; i++) {
        if (dist[i]!= INF) {
            printf("%d ", i);
        }
    }

    return 0;
}