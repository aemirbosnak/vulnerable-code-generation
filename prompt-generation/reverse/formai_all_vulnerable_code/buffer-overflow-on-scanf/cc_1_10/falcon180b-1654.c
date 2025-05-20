//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF 9999

int n, m, s, t, u, v, w, c[MAX_NODES], parent[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = INF;
        }
    }
}

void addedge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void dijkstra(int s) {
    for (int i = 0; i < n; i++) {
        c[i] = INF;
        parent[i] = -1;
    }

    c[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        int min = INF;

        for (int j = 0; j < n; j++) {
            if (c[j] < min && c[j]!= INF) {
                min = c[j];
                u = j;
            }
        }

        if (u == -1) break;

        for (int v = 0; v < n; v++) {
            if (graph[u][v]!= INF && (c[u] + graph[u][v] < c[v])) {
                c[v] = c[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printpath(int v) {
    if (v == -1) return;
    printpath(parent[v]);
    printf("%d ", v);
}

int main() {
    int i, j, k, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    init();

    printf("Enter edges with source, destination and weight:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &k);
        addedge(u, v, k);
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    dijkstra(s);

    printf("Vertex\tDistance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, c[i]);
    }

    printf("\nPath: ");
    printpath(t);

    return 0;
}