//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int connections[MAX_NODES];
    int connectionCount;
} Node;

typedef struct Network {
    Node nodes[MAX_NODES];
    int nodeCount;
} Network;

void initNetwork(Network* network) {
    network->nodeCount = 0;
}

int addNode(Network* network, const char* name) {
    if (network->nodeCount >= MAX_NODES) {
        printf("Network is full. Cannot add more nodes.\n");
        return -1;
    }
    strncpy(network->nodes[network->nodeCount].name, name, MAX_NAME_LENGTH);
    network->nodes[network->nodeCount].connectionCount = 0;
    network->nodeCount++;
    return network->nodeCount - 1;
}

int addConnection(Network* network, const char* source, const char* target) {
    int sourceIndex = -1, targetIndex = -1;

    for (int i = 0; i < network->nodeCount; i++) {
        if (strcmp(network->nodes[i].name, source) == 0) {
            sourceIndex = i;
        }
        if (strcmp(network->nodes[i].name, target) == 0) {
            targetIndex = i;
        }
    }

    if (sourceIndex == -1 || targetIndex == -1) {
        printf("Either source or target node not found.\n");
        return -1;
    }

    // Prevent duplicate connections
    for (int i = 0; i < network->nodes[sourceIndex].connectionCount; i++) {
        if (network->nodes[sourceIndex].connections[i] == targetIndex) {
            printf("Connection already exists between %s and %s.\n", source, target);
            return -1;
        }
    }

    network->nodes[sourceIndex].connections[network->nodes[sourceIndex].connectionCount++] = targetIndex;
    network->nodes[targetIndex].connections[network->nodes[targetIndex].connectionCount++] = sourceIndex; // Bidirectional
    return 0;
}

void printNetworkTopology(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->nodeCount; i++) {
        printf("%s:", network->nodes[i].name);
        for (int j = 0; j < network->nodes[i].connectionCount; j++) {
            printf(" %s", network->nodes[network->nodes[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    Network network;
    initNetwork(&network);
    
    int choice;
    char name[MAX_NAME_LENGTH], source[MAX_NAME_LENGTH], target[MAX_NAME_LENGTH];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Print Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

                if (addNode(&network, name) != -1) {
                    printf("Node %s added successfully.\n", name);
                }
                break;
            case 2:
                printf("Enter source node name: ");
                fgets(source, MAX_NAME_LENGTH, stdin);
                source[strcspn(source, "\n")] = 0;

                printf("Enter target node name: ");
                fgets(target, MAX_NAME_LENGTH, stdin);
                target[strcspn(target, "\n")] = 0;

                if (addConnection(&network, source, target) == 0) {
                    printf("Connection added between %s and %s.\n", source, target);
                }
                break;
            case 3:
                printNetworkTopology(&network);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}