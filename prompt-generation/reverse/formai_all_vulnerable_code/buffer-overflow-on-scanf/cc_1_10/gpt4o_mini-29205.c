//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct {
    char name[30];
    int connectionCount;
    int connections[MAX_CONNECTIONS];
} Node;

Node nodes[MAX_NODES];
int nodeCount = 0;

void addNode(char *name) {
    if (nodeCount < MAX_NODES) {
        strcpy(nodes[nodeCount].name, name);
        nodes[nodeCount].connectionCount = 0;
        nodeCount++;
    } else {
        printf("Max nodes reached. Cannot add more nodes.\n");
    }
}

void addConnection(char *fromNode, char *toNode) {
    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i].name, fromNode) == 0) {
            fromIndex = i;
        }
        if (strcmp(nodes[i].name, toNode) == 0) {
            toIndex = i;
        }
    }

    if (fromIndex != -1 && toIndex != -1) {
        if (nodes[fromIndex].connectionCount < MAX_CONNECTIONS) {
            nodes[fromIndex].connections[nodes[fromIndex].connectionCount++] = toIndex;
        } else {
            printf("Node %s has reached maximum connection limit.\n", fromNode);
        }
    } else {
        printf("One of the nodes does not exist!\n");
    }
}

void printTopology() {
    printf("Network Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node: %s -> Connected to: ", nodes[i].name);
        for (int j = 0; j < nodes[i].connectionCount; j++) {
            printf("%s ", nodes[nodes[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    char operation[10];
    char nodeName[30], fromNode[30], toNode[30];

    printf("Welcome to the Network Topology Mapper!\n");
    printf("Available operations: addNode, addConnection, showTopology, exit\n");

    while (1) {
        printf("\nEnter an operation: ");
        scanf("%s", operation);

        if (strcmp(operation, "addNode") == 0) {
            printf("Enter node name: ");
            scanf("%s", nodeName);
            addNode(nodeName);
        } else if (strcmp(operation, "addConnection") == 0) {
            printf("Enter source node name: ");
            scanf("%s", fromNode);
            printf("Enter destination node name: ");
            scanf("%s", toNode);
            addConnection(fromNode, toNode);
        } else if (strcmp(operation, "showTopology") == 0) {
            printTopology();
        } else if (strcmp(operation, "exit") == 0) {
            break;
        } else {
            printf("Invalid operation! Please try again.\n");
        }
    }

    printf("Exiting the Network Topology Mapper. Goodbye!\n");
    return 0;
}