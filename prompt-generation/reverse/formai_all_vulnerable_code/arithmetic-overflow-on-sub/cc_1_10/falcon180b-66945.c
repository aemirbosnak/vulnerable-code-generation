//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

int n, m, s;
Edge e[MAX_EDGES];
int dist[MAX_NODES];
int prev[MAX_NODES];

void bellmanFord(int start) {
    int i, j, u, v;
    for (i = 1; i <= n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = e[j].u;
            v = e[j].v;
            if (dist[u]!= INF && dist[u] + e[j].w < dist[v]) {
                dist[v] = dist[u] + e[j].w;
                prev[v] = u;
            }
        }
    }
    for (j = 0; j < m; j++) {
        u = e[j].u;
        v = e[j].v;
        if (dist[u]!= INF && dist[u] + e[j].w < dist[v]) {
            printf("Negative cycle found!\n");
            exit(0);
        }
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the source node: ");
    scanf("%d", &s);
    printf("Enter the edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    bellmanFord(s);
    printf("Shortest distances from node %d:\n", s);
    for (i = 1; i <= n; i++) {
        if (dist[i]!= INF) {
            printf("%d %d\n", i, dist[i]);
        }
    }
    return 0;
}