//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 1000000
#define DEBUG 0

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int num_edges = 0;

int adj_list[MAX_NODES][MAX_NODES];
int num_nodes = 0;

void add_edge(int u, int v, int w) {
    edges[num_edges++] = (Edge) {.u = u,.v = v,.w = w};
    adj_list[u][v] = w;
}

void dijkstra(int start) {
    int dist[MAX_NODES];
    int prev[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < num_nodes; v++) {
            int new_dist = dist[u] + adj_list[u][v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                prev[v] = u;
            }
        }
    }

    printf("Shortest distances from node %d:\n", start);

    for (int i = 0; i < num_nodes; i++) {
        if (dist[i]!= INF)
            printf("%d: %d\n", i, dist[i]);
    }
}

int main() {
    int num_edges_input;
    int num_nodes_input;
    int start_node_input;

    printf("Enter number of edges: ");
    scanf("%d", &num_edges_input);

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes_input);

    printf("Enter starting node: ");
    scanf("%d", &start_node_input);

    for (int i = 0; i < num_edges_input; i++) {
        int u, v, w;

        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        add_edge(u, v, w);
    }

    dijkstra(start_node_input);

    return 0;
}