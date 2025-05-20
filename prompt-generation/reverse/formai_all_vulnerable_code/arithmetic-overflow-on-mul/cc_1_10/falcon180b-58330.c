//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Network topology mapper function
void map_topology(int num_nodes) {
    int **adjacency_matrix = (int **)malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        adjacency_matrix[i] = (int *)malloc(num_nodes * sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // Populate adjacency matrix with connections
    int num_connections = (num_nodes * (num_nodes - 1)) / 2;
    for (int i = 0; i < num_connections; i++) {
        int node1, node2;
        printf("Enter the IDs of two nodes to connect (separated by a space): ");
        scanf("%d %d", &node1, &node2);
        adjacency_matrix[node1][node2] = 1;
        adjacency_matrix[node2][node1] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (adjacency_matrix[i][j] == 1) {
                printf("%d ", adjacency_matrix[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_nodes; i++) {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    map_topology(num_nodes);

    return 0;
}