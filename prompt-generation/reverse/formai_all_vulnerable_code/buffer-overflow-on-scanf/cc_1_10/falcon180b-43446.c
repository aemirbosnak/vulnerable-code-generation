//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 10
#define MAX_E 20
#define INF 999999

int V, E;
int adj_matrix[MAX_V][MAX_V];
int dist[MAX_V];
bool visited[MAX_V];

void init_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj_matrix[i][j] = INF;
        }
    }

    printf("Enter the edges and their weights: ");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }
}

void dijkstra(int start_vertex) {
    int u, v;
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start_vertex] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (int j = 0; j < V; j++) {
            if (!visited[j]) {
                int new_dist = dist[u] + adj_matrix[u][j];

                if (new_dist < dist[j]) {
                    dist[j] = new_dist;
                }
            }
        }
    }
}

void print_solution() {
    printf("Vertex\t Distance\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    init_graph();
    int start_vertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(start_vertex);
    print_solution();

    return 0;
}