//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

int n, m, start, end;
Edge edges[MAX_EDGES];
int dist[MAX_NODES];
int parent[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            if (dist[u]!= INF && dist[u] + edges[j].w < dist[v]) {
                dist[v] = dist[u] + edges[j].w;
                parent[v] = u;
            }
        }
    }
}

void printSolution(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
        return;
    }
    printf("Path: ");
    int u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
    printf("\n");
}

int main() {
    int i, j, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    scanf("%d %d", &start, &end);
    dijkstra(start);
    printSolution(end);
    return 0;
}