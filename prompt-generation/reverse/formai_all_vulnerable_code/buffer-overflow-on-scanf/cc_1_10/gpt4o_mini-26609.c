//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int connections[MAX_NODES];
    int connectionCount;
} Node;

Node network[MAX_NODES];
int nodeCount = 0;

void addNode(const char* nodeName) {
    if (nodeCount >= MAX_NODES) {
        printf("Network is full. Cannot add more nodes.\n");
        return;
    }
    strncpy(network[nodeCount].name, nodeName, MAX_NAME_LENGTH);
    network[nodeCount].connectionCount = 0;
    nodeCount++;
    printf("Node '%s' added to the network.\n", nodeName);
}

void addConnection(const char* nodeA, const char* nodeB) {
    int indexA = -1, indexB = -1;
    
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(network[i].name, nodeA) == 0) {
            indexA = i;
        }
        if (strcmp(network[i].name, nodeB) == 0) {
            indexB = i;
        }
    }

    if (indexA == -1 || indexB == -1) {
        printf("One or both nodes not found in the network.\n");
        return;
    }

    if (network[indexA].connectionCount < MAX_NODES && network[indexB].connectionCount < MAX_NODES) {
        network[indexA].connections[network[indexA].connectionCount++] = indexB;
        network[indexB].connections[network[indexB].connectionCount++] = indexA;
        printf("Connection established between '%s' and '%s'.\n", nodeA, nodeB);
    } else {
        printf("Unable to establish connection, node connection limits reached.\n");
    }
}

void displayNetwork() {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node: %s\n", network[i].name);
        printf("Connected to: ");
        for (int j = 0; j < network[i].connectionCount; j++) {
            printf("%s ", network[network[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char nodeNameA[MAX_NAME_LENGTH], nodeNameB[MAX_NAME_LENGTH];

    do {
        printf("\nNetwork Topology Mapper Menu:\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer.

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(nodeNameA, MAX_NAME_LENGTH, stdin);
                nodeNameA[strcspn(nodeNameA, "\n")] = '\0'; // Remove newline character
                addNode(nodeNameA);
                break;

            case 2:
                printf("Enter first node name: ");
                fgets(nodeNameA, MAX_NAME_LENGTH, stdin);
                nodeNameA[strcspn(nodeNameA, "\n")] = '\0'; // Remove newline character
                printf("Enter second node name: ");
                fgets(nodeNameB, MAX_NAME_LENGTH, stdin);
                nodeNameB[strcspn(nodeNameB, "\n")] = '\0'; // Remove newline character
                addConnection(nodeNameA, nodeNameB);
                break;

            case 3:
                displayNetwork();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}