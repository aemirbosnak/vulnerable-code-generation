//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int u, v, w;
} Edge;

int dist[MAX_NODES];
int parent[MAX_NODES];
int n, m;
Edge edges[MAX_EDGES];

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        for (int j = 0; j < n; j++) {
            if (dist[j] > dist[u] + edges[j].w) {
                dist[j] = dist[u] + edges[j].w;
                parent[j] = u;
            }
        }
    }
}

void print_path(int node) {
    if (node == -1) {
        return;
    }

    print_path(parent[node]);
    printf("%d ", node);
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v w):\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        edges[i] = (Edge) { u, v, w };
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(u);

    printf("\nShortest path from node %d to all other nodes:\n", u);

    for (i = 0; i < n; i++) {
        printf("%d -> ", u);
        print_path(i);
        printf("\n");
    }

    return 0;
}