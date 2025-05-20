//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int node;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int adj_matrix[MAX_NODES][MAX_NODES];
int n_nodes, n_edges;

void dijkstra(int start) {
    int i, j, u, v;
    int dist[MAX_NODES];

    for (i = 0; i < n_nodes; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (i = 0; i < n_nodes - 1; i++) {
        for (j = 0; j < n_nodes; j++) {
            if (adj_matrix[j][i]!= INF && dist[j] > dist[i] + adj_matrix[j][i]) {
                dist[j] = dist[i] + adj_matrix[j][i];
            }
        }
    }

    printf("Node\tDistance from Start\n");
    for (i = 0; i < n_nodes; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &n_edges);

    for (i = 0; i < n_edges; i++) {
        printf("Enter the nodes and weight for edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        scanf("%d", &w);

        edges[i].node = v;
        edges[i].weight = w;

        adj_matrix[u][v] = w;
    }

    printf("Enter the starting node: ");
    scanf("%d", &u);

    dijkstra(u);

    return 0;
}