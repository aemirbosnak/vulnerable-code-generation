//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 500
#define INF 100000

int V, E;
int dist[MAX_V];
int parent[MAX_V];
int adj_matrix[MAX_V][MAX_V];

void bellman_ford(int s) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (adj_matrix[u][v] > 0 && dist[u]!= INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj_matrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adj_matrix[u][v] > 0 && dist[u]!= INF && dist[u] + adj_matrix[u][v] == dist[v]) {
                printf("Negative cycle found!\n");
                exit(0);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    printf("Enter the edges with their weights:\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    printf("Enter the starting vertex:\n");
    int s;
    scanf("%d", &s);

    bellman_ford(s);

    printf("The shortest distances from vertex %d are:\n", s);
    for (int i = 0; i < V; i++) {
        if (dist[i]!= INF) {
            printf("%d ", dist[i]);
        } else {
            printf("INF ");
        }
    }

    return 0;
}