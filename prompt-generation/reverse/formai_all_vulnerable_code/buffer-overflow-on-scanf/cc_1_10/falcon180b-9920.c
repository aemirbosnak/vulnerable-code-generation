//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF 9999999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, start, end;
int dist[MAX_NODES], parent[MAX_NODES];

void dijkstra(int src) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    dist[v] = dist[u] + edges[i].w;
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int v) {
    if (v == -1)
        return;
    print_path(parent[v]);
    printf("%d ", v);
}

int main() {
    int i, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    scanf("%d %d", &start, &end);
    dijkstra(start);
    printf("Shortest path: ");
    print_path(end);
    printf("\nDistance: %d\n", dist[end]);
    return 0;
}