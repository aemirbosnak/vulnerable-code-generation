//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTEX 100
#define INF 10000000

typedef struct {
    int vertex;
    int weight;
} Edge;

Edge graph[MAX_VERTEX][MAX_VERTEX]; // Adjacency matrix representation of graph
int vertex_count; // Number of vertices in graph

void add_edge(int u, int v, int w) {
    graph[u][v] = (Edge) {v, w};
    graph[v][u] = (Edge) {u, w}; // For undirected graph
}

void dijkstra(int start_vertex) {
    int distance[MAX_VERTEX];
    int visited[MAX_VERTEX];

    for (int i = 0; i < vertex_count; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start_vertex] = 0;

    for (int i = 0; i < vertex_count - 1; i++) {
        int u = -1;
        int min_distance = INF;

        for (int j = 0; j < vertex_count; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < vertex_count; v++) {
            Edge edge = graph[u][v];

            if (distance[u]!= INF && distance[u] + edge.weight < distance[v]) {
                distance[v] = distance[u] + edge.weight;
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < vertex_count; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
}

int main() {
    int edge_count;
    printf("Enter number of edges: ");
    scanf("%d", &edge_count);

    printf("Enter number of vertices: ");
    scanf("%d", &vertex_count);

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < edge_count; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    int start_vertex;
    printf("Enter starting vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(start_vertex);

    return 0;
}