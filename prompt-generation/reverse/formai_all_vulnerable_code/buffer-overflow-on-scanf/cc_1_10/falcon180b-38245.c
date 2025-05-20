//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF (1 << 30)

typedef struct {
    int node;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int n, m, start, end, u, v, w;

void add_edge(int u, int v, int w) {
    edges[m].node = v;
    edges[m].weight = w;
    edges[m++].node = u;
}

void dijkstra(int start) {
    int i, j, k, min_dist;
    int dist[MAX_NODES];

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].node;
            v = edges[j].weight;

            if (dist[u]!= INF && dist[u] + v < dist[v])
                dist[v] = dist[u] + v;
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u, v, weight):\n");

    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &start, &end, &w);
        add_edge(start, end, w);
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}