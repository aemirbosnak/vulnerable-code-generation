//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Structure for a Circuit Node
struct node {
    char name[10];
    int value;
    int connections[MAX_NODES];
    int num_connections;
};

// Global Variables
int num_nodes;
struct node circuit[MAX_NODES];

// Add Connection between two Nodes
void addConnection(int node1, int node2) {
    circuit[node1].connections[circuit[node1].num_connections++] = node2;
    circuit[node2].connections[circuit[node2].num_connections++] = node1;
}

// Main Function to Simuate the Circuit
void simulateCircuit() {
    int i, j;
    int changed = 1;

    while (changed) {
        changed = 0;
        // Iterate through all the Nodes
        for (i = 0; i < num_nodes; i++) {
            int sum = 0;
            // Add up the values of all the connected nodes
            for (j = 0; j < circuit[i].num_connections; j++) {
                sum += circuit[circuit[i].connections[j]].value;
            }
            // If sum is ODD, set value to 1. If EVEN, set to 0.
            if (sum % 2 != circuit[i].value) {
                circuit[i].value = !circuit[i].value;
                changed = 1;
            }
        }
    }
}

int main() {
    int i, j;

    // Enter Number of Nodes
    printf("Enter number of Nodes: ");
    scanf("%d", &num_nodes);

    // Enter Node Names and Initial Values
    for (i = 0; i < num_nodes; i++) {
        printf("Enter name and initial value of Node %d: ", i+1);
        scanf("%s %d", circuit[i].name, &circuit[i].value);
        circuit[i].num_connections = 0;
    }

    // Enter Connections between Nodes
    printf("Enter connections between Nodes in the format: Node1 Node2\n");
    printf("Enter -1 -1 to stop: \n");
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    while (node1 != -1 && node2 != -1) {
        addConnection(node1-1, node2-1);
        printf("Enter connections between Nodes in the format: Node1 Node2\n");
        scanf("%d %d", &node1, &node2);
    }

    // Simulate the Circuit
    simulateCircuit();

    // Print Node Values
    printf("Final node values: \n");
    for (i = 0; i < num_nodes; i++) {
        printf("%s: %d\n", circuit[i].name, circuit[i].value);
    }

    return 0;
}