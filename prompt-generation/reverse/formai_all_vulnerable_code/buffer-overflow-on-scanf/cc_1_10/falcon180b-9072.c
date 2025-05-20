//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 9999

typedef struct edge {
    int from;
    int to;
    int weight;
} Edge;

int n, m;
int edges[MAX_EDGES];
int adj_list[MAX_NODES][MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (dist[j] > dist[u] + edges[edges[u] + 1]) {
                dist[j] = dist[u] + edges[edges[u] + 1];
            }
        }
    }

    for (i = 0; i < m; i++) {
        u = edges[i];
        v = edges[i + 1];

        if (dist[u]!= INF && dist[u] + edges[u] + 1 == dist[v]) {
            adj_list[u][v] = 1;
            adj_list[v][u] = 1;
        }
    }
}

void main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the edges (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = u;
        edges[i + 1] = v;
    }

    dijkstra(0);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj_list[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}