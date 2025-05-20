//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 20

struct Edge {
    int start_node;
    int end_node;
    double value;
};

struct Node {
    int node_number;
    double voltage;
    double current;
};

int main() {
    struct Node nodes[MAX_NODES];
    struct Edge edges[MAX_EDGES];

    // Initialize nodes
    for(int i = 0; i < MAX_NODES; i++) {
        struct Node node = { i, 0, 0 };
        nodes[i] = node;
    }

    // Initialize edges
    struct Edge edge1 = { 0, 1, 1 };
    struct Edge edge2 = { 1, 2, 2 };
    struct Edge edge3 = { 0, 3, 3 };
    struct Edge edge4 = { 3, 2, 4 };
    edges[0] = edge1;
    edges[1] = edge2;
    edges[2] = edge3;
    edges[3] = edge4;

    // Simulate the circuit
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < MAX_EDGES; j++) {
            int start_node = edges[j].start_node;
            int end_node = edges[j].end_node;
            double value = edges[j].value;

            nodes[start_node].current += (nodes[start_node].voltage - nodes[end_node].voltage) * value;
            nodes[end_node].current += (nodes[end_node].voltage - nodes[start_node].voltage) * value;
        }

        for(int j = 0; j < MAX_NODES; j++) {
            if(j == 0) {
                nodes[j].voltage = 10;
            }
            else if(j == 2) {
                nodes[j].voltage = 0;
            }
            else {
                nodes[j].voltage = nodes[j].current;
            }
            nodes[j].current = 0;
        }

        printf("Iteration %d: Node Voltages\n", i);
        for(int j = 0; j < MAX_NODES; j++) {
            printf("Node %d: %f\n", nodes[j].node_number, nodes[j].voltage);
        }
    }

    return 0;
}