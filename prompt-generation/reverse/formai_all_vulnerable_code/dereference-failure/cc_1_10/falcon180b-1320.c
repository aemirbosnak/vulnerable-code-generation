//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Edge {
    int u, v, w;
};

struct Graph {
    int n, m;
    struct Edge edges[MAX_EDGES];
};

void addEdge(struct Graph *graph, int u, int v, int w) {
    graph->edges[graph->m++] = (struct Edge) {.u = u,.v = v,.w = w };
}

void dijkstra(struct Graph *graph, int src, int dist[MAX_NODES]) {
    int n = graph->n, m = graph->m;
    int visited[MAX_NODES];
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[j]!= INF && dist[j] + graph->edges[i].w < dist[graph->edges[i].v])
                dist[graph->edges[i].v] = dist[j] + graph->edges[i].w;
        }
    }
}

void printSolution(int dist[MAX_NODES], int n) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    struct Graph graph;
    int n, m;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    graph.n = n;
    graph.m = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v, w);
    }

    int src;
    printf("Enter source node: ");
    scanf("%d", &src);

    int dist[MAX_NODES];
    dijkstra(&graph, src, dist);

    printf("Shortest distances from node %d:\n", src);
    printSolution(dist, n);

    return 0;
}