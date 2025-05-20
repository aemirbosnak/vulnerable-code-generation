//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int n, m;
int dist[MAX_NODES];
int parent[MAX_NODES];
Edge edges[MAX_EDGES];

void dijkstra(int start) {
    int i, j;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u]!= INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            parent[v] = u;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i]!= INF && dist[i] + dist[j] < dist[j]) {
                dist[j] = dist[i] + dist[j];
                parent[j] = i;
            }
        }
    }
}

void print_path(int node, int dest) {
    if (node == -1) {
        return;
    }
    print_path(parent[node], dest);
    printf("%d ", node);
}

int main() {
    int i, j, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }
    for (i = 0; i < n; i++) {
        dijkstra(i);
    }
    int source, dest;
    scanf("%d %d", &source, &dest);
    if (dist[dest] == INF) {
        printf("No path found.\n");
    } else {
        printf("Shortest path: ");
        print_path(dest, dest);
        printf(" -> %d\n", source);
        printf("Total weight: %d\n", dist[dest]);
    }
    return 0;
}