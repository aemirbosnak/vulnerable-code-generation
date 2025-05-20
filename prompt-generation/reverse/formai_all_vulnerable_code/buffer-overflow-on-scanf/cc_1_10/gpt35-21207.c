//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_INPUTS 10

int main() {
    int num_nodes, num_inputs;
    int node_list[MAX_NODES], input_list[MAX_INPUTS];
    int circuit[MAX_NODES][MAX_NODES];

    printf("Welcome to the Classical Circuit Simulator!\n");

    // Get user input for number of nodes and inputs
    printf("How many nodes are in the circuit? (up to %d nodes)\n", MAX_NODES);
    scanf("%d", &num_nodes);

    printf("How many inputs does the circuit have? (up to %d inputs)\n", MAX_INPUTS);
    scanf("%d", &num_inputs);

    // Get user input for node list
    printf("Please enter the node numbers in the circuit.\n");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &node_list[i]);
    }

    // Get user input for input list
    printf("Please enter the input numbers in the circuit.\n");
    for (int i = 0; i < num_inputs; i++) {
        scanf("%d", &input_list[i]);
    }

    // Initialize circuit connectivity matrix
    memset(circuit, 0, sizeof(circuit));

    // Get user input for connectivity between nodes
    printf("Please enter the connections between nodes. Use 1 for connected and 0 for disconnected.\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            int connected;
            scanf("%d", &connected);
            circuit[i][j] = connected;
        }
    }

    // Simulate circuit
    printf("Starting simulation...\n");
    for (int i = 0; i < num_inputs; i++) {
        printf("Input: %d\n", input_list[i]);
        for (int j = 0; j < num_nodes; j++) {
            int output = input_list[i];
            for (int k = 0; k < num_nodes; k++) {
                if (circuit[k][j] == 1) {
                    output = output & node_list[k];
                }
            }
            printf("Node %d output: %d\n", node_list[j], output);
        }
    }
    printf("Done simulating! Thank you for using the Classical Circuit Simulator.\n");

    return 0;
}