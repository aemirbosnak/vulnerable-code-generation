//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

int n, m, s;
int dist[MAX_NODES];
int prev[MAX_NODES];
int visited[MAX_NODES];
Edge edges[MAX_EDGES];

void bellmanFord(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u]!= INF && dist[u] + edges[u * n + v].w < dist[v]) {
                    dist[v] = dist[u] + edges[u * n + v].w;
                    prev[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (dist[u]!= INF && dist[u] + edges[u * n + v].w < dist[v]) {
                printf("Negative cycle found!\n");
                exit(0);
            }
        }
    }
}

int main() {
    int i, j, k, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the source node: ");
    scanf("%d", &s);

    printf("Enter the edges in the form u v w:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }

    bellmanFord(s);

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}