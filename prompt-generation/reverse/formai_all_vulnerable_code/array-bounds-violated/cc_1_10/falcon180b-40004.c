//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF (1 << 30)

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, start, end;
int dist[MAX_NODES];
int prev[MAX_NODES];

void dijkstra(int s) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[s] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            if (dist[u]!= INF && dist[u] + edges[j].w < dist[v]) {
                dist[v] = dist[u] + edges[j].w;
                prev[v] = u;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}