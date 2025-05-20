//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 10 // Maximum number of network nodes

int adjacency_matrix[MAX_NODES][MAX_NODES]; // Global adjacency matrix to store network topology

// Function to add a new node to the network
void addNode(int node_num) {
    printf("Adding node %d to the network...\n", node_num);
    for (int i = 0; i < node_num; i++) {
        adjacency_matrix[node_num][i] = 0; // Initialize the new node's row to all 0s
    }
    for (int j = 0; j < node_num; j++) {
        adjacency_matrix[j][node_num] = 0; // Initialize the new node's column to all 0s
    }
}

// Function to add a new connection between two nodes in the network
void addConnection(int node1, int node2) {
    printf("Adding connection between node %d and node %d...\n", node1, node2);
    adjacency_matrix[node1][node2] = 1;
    adjacency_matrix[node2][node1] = 1;
}

// Function to print the network topology
void printTopology(int num_nodes) {
    printf("\nCurrent network topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the network topology mapper!\n");
    
    int num_nodes = 0;
    char input[10];
    bool running = true;

    while (running) {
        printf("\nPlease enter a command (add node, add connection, print topology, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Please enter the node number to add (0-%d): ", MAX_NODES - 1);
            scanf("%d", &num_nodes);
            if (num_nodes < MAX_NODES) {
                addNode(num_nodes);
                printf("Node %d added to the network!\n", num_nodes);
            } else {
                printf("Error: Cannot add more than %d nodes to the network!\n", MAX_NODES);
            }
        } else if (strcmp(input, "connect") == 0) {
            printf("Please enter the two node numbers to connect: ");
            int node1, node2;
            scanf("%d %d", &node1, &node2);
            if (node1 >= 0 && node1 < num_nodes && node2 >= 0 && node2 < num_nodes) {
                addConnection(node1, node2);
                printf("Connection between node %d and node %d added!\n", node1, node2);
            } else {
                printf("Error: Invalid node numbers!\n");
            }
        } else if (strcmp(input, "print") == 0) {
            printTopology(num_nodes);
        } else if (strcmp(input, "quit") == 0) {
            printf("Exiting network topology mapper...\n");
            running = false;
        } else {
            printf("Error: Invalid command!\n");
        }
    }

    return 0;
}