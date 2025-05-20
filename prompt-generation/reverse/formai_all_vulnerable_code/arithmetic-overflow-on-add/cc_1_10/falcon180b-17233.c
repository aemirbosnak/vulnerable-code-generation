//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 9999

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

int n, m;
Edge edges[MAX_EDGES];

void addEdge(int u, int v, int w) {
    edges[m++] = (Edge) {u, v, w};
}

void dijkstra(int start) {
    int dist[MAX_NODES];
    memset(dist, INF, sizeof(dist));

    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;

            if (dist[u]!= INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int start;
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}