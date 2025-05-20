//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Graph structure
typedef struct Graph {
    int num_nodes;
    int adj_matrix[MAX_NODES][MAX_NODES];
} Graph;

// Function to print the adjacency matrix
void print_adj_matrix(Graph *G) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < G->num_nodes; i++) {
        for (int j = 0; j < G->num_nodes; j++) {
            printf("%d ", G->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create the graph
void create_graph(Graph *G) {
    printf("Enter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &G->num_nodes);

    // Initialize adjacency matrix to all 0's
    for (int i = 0; i < G->num_nodes; i++) {
        for (int j = 0; j < G->num_nodes; j++) {
            G->adj_matrix[i][j] = 0;
        }
    }

    // Prompt user for edges and update adjacency matrix
    printf("Enter the edges:\n");
    int node1, node2;
    while (scanf("%d %d", &node1, &node2) == 2) {
        // Check if nodes are within range
        if (node1 >= G->num_nodes || node2 >= G->num_nodes) {
            printf("Invalid node! ");
            continue;
        }
        G->adj_matrix[node1][node2] = 1;
        G->adj_matrix[node2][node1] = 1;
    }
}

int main() {
    Graph G;

    // Create the graph
    create_graph(&G);

    // Print the adjacency matrix
    print_adj_matrix(&G);

    return 0;
}