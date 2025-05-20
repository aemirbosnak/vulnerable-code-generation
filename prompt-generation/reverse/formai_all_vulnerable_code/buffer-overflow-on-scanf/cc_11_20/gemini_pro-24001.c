//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// The main function.
int main() {
    // The number of nodes in the network.
    int num_nodes;

    // The adjacency matrix.
    int adj_matrix[100][100];

    // Get the number of nodes from the user.
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    // Get the adjacency matrix from the user.
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    // Print the adjacency matrix.
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Find the shortest path between every pair of nodes.
    int dist[100][100];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            dist[i][j] = adj_matrix[i][j];
        }
    }
    for (int k = 0; k < num_nodes; k++) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path matrix.
    printf("The shortest path matrix is:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}