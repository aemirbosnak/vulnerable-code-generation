//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_NODES 100

int adjacency_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

// Recursive function to perform DFS traversal
void DFS(int node, int num_nodes) {
    visited[node] = 1;
    printf("%d ", node);

    for(int i = 0; i < num_nodes; i++) {
        if(adjacency_matrix[node][i] && !visited[i]) {
            DFS(i, num_nodes);
        }
    }
}

int main() {
    printf("\nWelcome to the C Network Topology Mapper!\n\n");

    int num_nodes, num_edges;

    // Prompt user for number of nodes and edges
    printf("How many nodes are in your network? (Maximum %d)\n", MAX_NODES);
    scanf("%d", &num_nodes);
    printf("How many edges are in your network?\n");
    scanf("%d", &num_edges);
    printf("\n");

    // Initialize adjacency matrix to all 0's
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // Prompt user to input edge connections
    int start_node, end_node;
    for(int i = 0; i < num_edges; i++) {
        printf("Enter the start node and end node for edge %d:\n", i+1);
        scanf("%d %d", &start_node, &end_node);

        if(start_node < 1 || start_node > num_nodes || end_node < 1 || end_node > num_nodes) {
            printf("Invalid node numbers. Please try again.\n");
            i--;
            continue;
        }

        adjacency_matrix[start_node-1][end_node-1] = 1;
        adjacency_matrix[end_node-1][start_node-1] = 1;
    }

    printf("\nYour network topology has been successfully mapped:\n\n");

    // Perform DFS to print out network topology
    for(int i = 0; i < num_nodes; i++) {
        if(!visited[i]) {
            DFS(i, num_nodes);
            printf("\n");
        }
    }

    printf("\nThank you for using C Network Topology Mapper!");

    return 0;
}