//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

int main()
{
    int adjacency_matrix[MAX_NODES][MAX_NODES];
    int num_nodes, i, j;

    printf("Enter the number of nodes in the network topology: ");
    scanf("%d", &num_nodes);

    // Initialise adjacency matrix to all zeros
    memset(adjacency_matrix, 0, sizeof(adjacency_matrix));

    // Input adjacency matrix
    printf("Enter the adjacency matrix of the network topology (use 1 for connected and 0 for not connected):\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    // Print adjacency matrix
    printf("Adjacency matrix of the network topology:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    // Find connected nodes using Depth First Search
    int visited[MAX_NODES] = {0};
    visited[0] = 1;

    printf("Connected nodes in the network topology: 1 ");

    for (i = 1; i < num_nodes; i++) {
        if (adjacency_matrix[0][i] && !visited[i]) {
            visited[i] = 1;
            printf("%d ", i + 1); // Add 1 because nodes are zero-indexed
        }
    }

    for (i = 1; i < num_nodes; i++) {
        if (visited[i]) {
            for (j = 1; j < num_nodes; j++) {
                if (adjacency_matrix[i][j] && !visited[j]) {
                    visited[j] = 1;
                    printf("%d ", j + 1); // Add 1 because nodes are zero-indexed
                }
            }
        }
    }

    printf("\n");

    return 0;
}