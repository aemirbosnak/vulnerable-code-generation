//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100  // Maximum number of nodes in the network
#define INF 99999999   // Infinity value of the distance between nodes

// Function to perform the Floyd-Warshall algorithm for network topology mapping
void floydWarshall(int graph[][MAX_NODES], int n) {
    int i, j, k, dist[MAX_NODES][MAX_NODES];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the resulting network topology
    printf("Network Topology:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, num_edges, src, dst, weight, graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes in the network: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the network: ");
    scanf("%d", &num_edges);

    // Initialize the graph with infinity values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // Read in the edges and their weights
    printf("Enter the edges and their weights:\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d%d%d", &src, &dst, &weight);
        graph[src][dst] = weight;
    }

    // Perform the network topology mapping algorithm
    floydWarshall(graph, n);

    return 0;
}