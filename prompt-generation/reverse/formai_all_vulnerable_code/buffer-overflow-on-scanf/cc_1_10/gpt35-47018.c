//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 20

typedef struct {
    int node1;
    int node2;
    float resistance;
} Edge;

typedef struct {
    float voltage;
    float current;
    float power;
} Node;

int main() {
    Edge edges[MAX_EDGES];
    Node nodes[MAX_NODES];
    int num_nodes, num_edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (node1 node2 resistance):\n");
    for (int i=0; i<num_edges; i++) {
        scanf("%d %d %f", &edges[i].node1, &edges[i].node2, &edges[i].resistance);
    }

    for (int i=0; i<num_nodes; i++) {
        printf("Enter the voltage of node %d: ", i+1);
        scanf("%f", &nodes[i].voltage);
    }

    // Calculate currents and power for each node
    for (int i=0; i<num_nodes; i++) {
        float current = 0.0;
        for (int j=0; j<num_edges; j++) {
            if (edges[j].node1 == i+1) {
                current += nodes[i].voltage / edges[j].resistance;
                int node2 = edges[j].node2 - 1;
                nodes[node2].current -= nodes[i].voltage / edges[j].resistance;
            } else if (edges[j].node2 == i+1) {
                current -= nodes[i].voltage / edges[j].resistance;
                int node1 = edges[j].node1 - 1;
                nodes[node1].current += nodes[i].voltage / edges[j].resistance;
            }
        }
        nodes[i].current += current;
        nodes[i].power = nodes[i].voltage * nodes[i].current;
    }

    // Print results
    for (int i=0; i<num_nodes; i++) {
        printf("Node %d - Voltage: %.2fV, Current: %.2fA, Power: %.2fW\n", i+1, nodes[i].voltage, nodes[i].current, nodes[i].power);
    }

    return 0;
}