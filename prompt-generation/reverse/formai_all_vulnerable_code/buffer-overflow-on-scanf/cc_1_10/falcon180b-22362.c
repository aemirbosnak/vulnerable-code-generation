//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF INT_MAX

typedef struct {
    int v;
    int w;
    int next;
} edge;

void bellmanFord(int n, edge graph[MAX_EDGES], int source) {
    int i, j, u, v;
    int dist[n];
    for (i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[j].w!= INF && dist[j]!= INF && dist[j] + graph[j].w < dist[graph[j].v])
                dist[graph[j].v] = dist[j] + graph[j].w;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[j].w!= INF && dist[j]!= INF && dist[j] + graph[j].w < dist[graph[j].v]) {
                printf("Negative cycle found\n");
                return;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int n, m, i, u, v, w;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    edge graph[m];
    printf("Enter the edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].v = v;
        graph[i].w = w;
        graph[i].next = -1;
    }

    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);

    bellmanFord(n, graph, source);

    return 0;
}