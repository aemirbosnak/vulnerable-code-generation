//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 100

// Define the structure for each node in the network
typedef struct {
    char name[50]; // Name of the node
    int num_connections; // Number of connections to other nodes
    int *connected_nodes; // Array of indices of nodes this node is connected to
} Node;

// Function to initialize a node with the given name and number of connections
void init_node(Node *node, char *name, int num_connections) {
    strcpy(node->name, name);
    node->num_connections = num_connections;
    node->connected_nodes = (int *)malloc(num_connections * sizeof(int));
}

// Function to connect two nodes in the network
void connect_nodes(Node *node1, Node *node2) {
    // Add node2 to the list of connected nodes for node1
    node1->connected_nodes[node1->num_connections++] = node2 - node1;
}

// Function to print the network topology
void print_topology(Node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i, nodes[i].name);
        printf("Number of connections: %d\n", nodes[i].num_connections);
        printf("Connected nodes: ");
        for (int j = 0; j < nodes[i].num_connections; j++) {
            printf("%d ", nodes[i].connected_nodes[j] + i);
        }
        printf("\n");
    }
}

// Main function to initialize and connect nodes in the network
int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;

    // Initialize node 1
    init_node(&nodes[num_nodes++], "Node 1", 2);

    // Initialize node 2
    init_node(&nodes[num_nodes++], "Node 2", 1);

    // Initialize node 3
    init_node(&nodes[num_nodes++], "Node 3", 2);

    // Connect node 1 to node 2
    connect_nodes(&nodes[0], &nodes[1]);

    // Connect node 1 to node 3
    connect_nodes(&nodes[0], &nodes[2]);

    // Connect node 2 to node 3
    connect_nodes(&nodes[1], &nodes[2]);

    // Print the network topology
    print_topology(nodes, num_nodes);

    return 0;
}