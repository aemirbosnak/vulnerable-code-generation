//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define INF 999999

typedef struct {
    int v;
    int w;
    int next;
} Edge;

Edge graph[MAX_NODES][MAX_NODES];

void add_edge(int u, int v, int w) {
    graph[u][v].v = v;
    graph[u][v].w = w;
    graph[u][v].next = u;
}

void dijkstra(int start) {
    int u, v, i, j;
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (u = 0; u < MAX_NODES; u++) {
        dist[u] = INF;
        visited[u] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        for (u = 0; u < MAX_NODES; u++) {
            for (v = 0; v < MAX_NODES; v++) {
                if (graph[u][v].v!= -1 && dist[u]!= INF && dist[u] + graph[u][v].w < dist[v]) {
                    dist[v] = dist[u] + graph[u][v].w;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (u = 0; u < MAX_NODES; u++) {
        printf("%d\t\t%d\n", u, dist[u]);
    }
}

int main() {
    int n, m, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (u = 0; u < n; u++) {
        for (v = 0; v < n; v++) {
            graph[u][v].v = -1;
            graph[u][v].w = -1;
            graph[u][v].next = -1;
        }
    }

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(u);

    return 0;
}