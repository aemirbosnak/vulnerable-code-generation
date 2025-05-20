//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 10

/* A Node in our Network Topology */
struct Node {
    char name[10];
    bool connected[MAX_NODES];
    int numConnections;
};

/* Function to print the network topology */
void printTopology(struct Node nodes[]) {
    printf("Network Topology:\n");
    for(int i=0; i<MAX_NODES; i++) {
        printf("\t%s is connected to: ", nodes[i].name);
        for(int j=0; j<MAX_NODES; j++) {
            if(nodes[i].connected[j]) {
                printf("%s ", nodes[j].name);
            }
        }
        printf("\n");
    }
}

/* Function to get the index of a node by name */
int getNodeIndex(char name[], struct Node nodes[]) {
    for(int i=0; i<MAX_NODES; i++) {
        if(strcmp(name, nodes[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Node nodes[MAX_NODES];
    int numNodes = 0;

    printf("Welcome to Network Topology Mapper!\n");
    printf("Add nodes to the network topology.\n");
    printf("Enter -1 to stop adding nodes.\n");

    // Loop to add nodes
    while(numNodes < MAX_NODES) {
        char newName[10];
        printf("Enter the name of node %d: ", numNodes+1);
        scanf("%s", newName);

        // Check if user wants to stop adding nodes
        if(strcmp(newName, "-1") == 0) {
            break;
        }

        // Check if node with same name already exists
        if(getNodeIndex(newName, nodes) != -1) {
            printf("%s already exists.\n", newName);
            continue;
        }

        // Add new node
        strcpy(nodes[numNodes].name, newName);
        nodes[numNodes].numConnections = 0;
        for(int i=0; i<MAX_NODES; i++) {
            nodes[numNodes].connected[i] = false;
        }
        numNodes++;
    }

    // Loop to add connections
    char input[20];
    printf("\nAdd connections between nodes.\n");
    printf("Enter 'done' to stop adding connections.\n");
    while(strcmp(input, "done") != 0) {
        char startName[10], endName[10];
        printf("Enter the start node and end node of the connection (separated by space): ");
        scanf("%s", startName);
        if(strcmp(startName, "done") == 0) {
            break;
        }
        scanf("%s", endName);

        // Get the indices of the nodes
        int startIndex = getNodeIndex(startName, nodes);
        int endIndex = getNodeIndex(endName, nodes);

        // Check if nodes exist
        if(startIndex == -1 || endIndex == -1) {
            printf("Invalid node name(s).\n");
            continue;
        }

        // Add the connection
        nodes[startIndex].connected[endIndex] = true;
        nodes[startIndex].numConnections++;
    }

    // Print the network topology
    printTopology(nodes);

    return 0;
}