//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 1000000000

int start_node, end_node;
int dist[MAX_NODES];
int parent[MAX_NODES];
int n_nodes, n_edges;
int adj_matrix[MAX_NODES][MAX_NODES];

void dijkstra(int start) {
    int i, u, v;
    int min_dist = INF, u_min = -1;

    for (i = 0; i < n_nodes; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n_nodes - 1; i++) {
        min_dist = INF;
        u_min = -1;

        for (u = 0; u < n_nodes; u++) {
            if (dist[u] < min_dist && dist[u]!= INF) {
                min_dist = dist[u];
                u_min = u;
            }
        }

        for (v = 0; v < n_nodes; v++) {
            if (adj_matrix[u_min][v]!= INF && dist[u_min]!= INF && dist[u_min] + adj_matrix[u_min][v] < dist[v]) {
                dist[v] = dist[u_min] + adj_matrix[u_min][v];
                parent[v] = u_min;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;
    int start_time, end_time;

    srand(time(NULL));

    printf("Enter the number of nodes: ");
    scanf("%d", &n_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &n_edges);

    printf("Enter the start node: ");
    scanf("%d", &start_node);

    printf("Enter the end node: ");
    scanf("%d", &end_node);

    for (i = 0; i < n_nodes; i++) {
        for (j = 0; j < n_nodes; j++) {
            adj_matrix[i][j] = INF;
        }
    }

    for (i = 0; i < n_edges; i++) {
        printf("Enter the source and destination nodes for edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        printf("Enter the weight of the edge: ");
        scanf("%d", &w);

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    start_time = clock();
    dijkstra(start_node);
    end_time = clock();

    printf("The shortest path from node %d to node %d is:\n", start_node, end_node);

    if (dist[end_node] == INF) {
        printf("No path found.\n");
    } else {
        int v = end_node;
        while (v!= -1) {
            printf("%d ", v);
            v = parent[v];
        }
        printf("\n");
    }

    printf("Time taken: %f seconds.\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}