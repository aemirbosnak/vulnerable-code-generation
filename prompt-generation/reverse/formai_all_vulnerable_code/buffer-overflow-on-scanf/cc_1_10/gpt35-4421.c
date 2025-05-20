//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100  // Maximum number of nodes in the network
#define MAX_EDGES 200  // Maximum number of edges in the network

typedef struct {
    int source;     // Source node
    int destination // Destination node
} Edge;

int nodes[MAX_NODES];   // Array to store all nodes in the network
Edge edges[MAX_EDGES];  // Array to store all edges in the network
int num_nodes, num_edges;

int main() {
    printf("Welcome to the Network Topology Mapper!\n");

    // Prompt user for number of nodes and edges
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges in the network: ");
    scanf("%d", &num_edges);

    // Prompt user for all nodes in the network
    printf("Enter all nodes in the network: ");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &nodes[i]);
    }

    // Prompt user for all edges in the network
    printf("Enter all edges in the network (use space to separate the source and destination nodes): ");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[i].source, &edges[i].destination);
    }

    // Print all nodes and edges in the network
    printf("The network topology is:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", nodes[i]);
    }
    printf("\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d-%d ", edges[i].source, edges[i].destination);
    }
    printf("\n");

    return 0;
}