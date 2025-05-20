//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 99999

typedef struct {
    int v;
    int w;
} Edge;

void addEdge(Edge edges[], int u, int v, int w) {
    edges[u].v = v;
    edges[u].w = w;
}

void dijkstra(int vertices, Edge edges[], int src) {
    int dist[vertices];
    int visited[vertices];
    int i, u, v;

    for (i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < vertices - 1; i++) {
        for (u = 0; u < vertices; u++) {
            for (v = 0; v < vertices; v++) {
                if (dist[u]!= INF && dist[u] + edges[u].w < dist[v]) {
                    dist[v] = dist[u] + edges[u].w;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < vertices; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int vertices, edges;
    int i, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Edge graph[MAX_EDGE];

    printf("Enter the edges with their weights:\n");
    for (i = 0; i < edges; i++) {
        printf("Enter the source vertex: ");
        scanf("%d", &u);

        printf("Enter the destination vertex: ");
        scanf("%d", &v);

        printf("Enter the weight of the edge: ");
        scanf("%d", &w);

        addEdge(graph, u, v, w);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(vertices, graph, source);

    return 0;
}