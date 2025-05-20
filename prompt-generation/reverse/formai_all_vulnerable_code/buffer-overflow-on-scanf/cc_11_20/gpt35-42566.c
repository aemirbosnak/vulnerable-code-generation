//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50   // Maximum length for strings
#define MAX_NODES 10    // Maximum number of nodes in the network
#define MAX_EDGES 20    // Maximum number of edges in the network

typedef struct {
    char name[MAX_LENGTH];
} Node;

typedef struct {
    Node* from;
    Node* to;
} Edge;

int main() {
    int numNodes, numEdges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    // Get the number of nodes from the user
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &numNodes);

    // Get the names of the nodes from the user
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", nodes[i].name);
    }

    // Get the number of edges from the user
    printf("Enter the number of edges in the network: ");
    scanf("%d", &numEdges);

    // Get the edges from the user
    for (int i = 0; i < numEdges; i++) {
        char fromName[MAX_LENGTH], toName[MAX_LENGTH];
        printf("Enter the name of the node the edge starts from: ");
        scanf("%s", fromName);
        printf("Enter the name of the node the edge goes to: ");
        scanf("%s", toName);

        // Find the nodes with the given names
        Node* fromNode = NULL;
        Node* toNode = NULL;
        for (int j = 0; j < numNodes; j++) {
            if (strcmp(nodes[j].name, fromName) == 0) {
                fromNode = &nodes[j];
            }
            if (strcmp(nodes[j].name, toName) == 0) {
                toNode = &nodes[j];
            }
        }

        // Make sure the nodes were found
        if (fromNode == NULL || toNode == NULL) {
            printf("Error: Could not find nodes corresponding to the given names.\n");
            exit(1);
        }

        // Add the edge to the list of edges
        edges[i].from = fromNode;
        edges[i].to = toNode;
    }

    // Print out the network topology
    printf("Network topology:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %s is connected to: ", nodes[i].name);
        for (int j = 0; j < numEdges; j++) {
            if (edges[j].from == &nodes[i]) {
                printf("%s ", edges[j].to->name);
            } else if (edges[j].to == &nodes[i]) {
                printf("%s ", edges[j].from->name);
            }
        }
        printf("\n");
    }

    return 0;
}