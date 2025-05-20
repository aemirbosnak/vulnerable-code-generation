//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int n;
    int e;
    struct Edge edges[MAX_EDGES];
};

void dijkstra(struct Graph* graph, int start) {
    int i, j, k;
    int n = graph->n;
    int dist[n];
    bool visited[n];

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        int u = -1;
        int min_dist = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int v = j;
                int new_dist = dist[u] + graph->edges[u].weight;

                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                }
            }
        }
    }

    printf("Vertex\tDistance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    struct Graph graph;
    int i, j, k;
    int n, m;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph.n = n;
    graph.e = m;

    printf("Enter the edges (src dest weight):\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    int start;

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(&graph, start);

    return 0;
}