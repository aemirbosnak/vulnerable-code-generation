//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 100

// Define the structure of a node
typedef struct {
    char name[20];
    int connections[MAX_NODES];
} Node;

// Function to print the topology of the network
void printTopology(Node* nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %s\n", i, nodes[i].name);
        printf("Connections: ");
        for (int j = 0; j < MAX_NODES; j++) {
            if (nodes[i].connections[j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function to create a new node
void createNode(Node* nodes, int numNodes, char* name) {
    strcpy(nodes[numNodes].name, name);
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[numNodes].connections[i] = 0;
    }
    numNodes++;
}

// Function to connect two nodes
void connectNodes(Node* nodes, int numNodes, int node1, int node2) {
    nodes[node1].connections[node2] = 1;
    nodes[node2].connections[node1] = 1;
}

// Function to create the network topology recursively
void createNetwork(Node* nodes, int numNodes) {
    char name[20];
    printf("Enter the name of the next node (or press enter to finish): ");
    scanf("%s", name);
    if (name[0]!= '\0') {
        createNode(nodes, numNodes, name);
        printf("Enter the nodes this node is connected to (separated by spaces): ");
        int numConnections;
        scanf("%d", &numConnections);
        for (int i = 0; i < numConnections; i++) {
            int node;
            scanf("%d", &node);
            connectNodes(nodes, numNodes, numNodes - 1, node - 1);
        }
        createNetwork(nodes, numNodes);
    }
}

int main() {
    Node nodes[MAX_NODES];
    int numNodes = 0;

    // Create the first node
    strcpy(nodes[numNodes].name, "Node 1");
    numNodes++;

    // Create the rest of the network topology recursively
    createNetwork(nodes, numNodes);

    // Print the topology of the network
    printTopology(nodes, numNodes);

    return 0;
}