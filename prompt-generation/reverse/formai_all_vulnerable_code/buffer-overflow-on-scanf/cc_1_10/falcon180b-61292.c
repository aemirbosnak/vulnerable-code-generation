//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_V 100
#define MAX_E 200
#define INF 99999

int V, E;
int adj_matrix[MAX_V][MAX_V];
int dist[MAX_V];
int visited[MAX_V];

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            adj_matrix[i][j] = INF;
        }
    }
}

void dijkstra(int start_vertex) {
    int i, j, u;
    int min_dist = INF;
    int min_index;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start_vertex] = 0;

    for (i = 0; i < V - 1; i++) {
        for (j = 0; j < V; j++) {
            for (u = 0; u < V; u++) {
                if ((dist[j] + adj_matrix[j][u]) < dist[u]) {
                    dist[u] = dist[j] + adj_matrix[j][u];
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    init_graph();

    printf("Enter the edges with their weights:\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &u);

    dijkstra(u);

    return 0;
}