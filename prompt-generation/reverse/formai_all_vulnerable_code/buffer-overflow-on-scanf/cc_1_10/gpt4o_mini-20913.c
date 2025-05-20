//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 100

typedef struct {
    int id;
    char name[30];
    int connections[MAX_CONNECTIONS];
    int connectionCount;
} Node;

Node network[MAX_NODES];
int nodeCount = 0;

void addNode(char *name) {
    if (nodeCount < MAX_NODES) {
        network[nodeCount].id = nodeCount;
        strcpy(network[nodeCount].name, name);
        network[nodeCount].connectionCount = 0;
        nodeCount++;
        printf("Node %d (%s) added to the network.\n", nodeCount - 1, name);
    } else {
        printf("Node limit reached, cannot add more nodes.\n");
    }
}

void addConnection(int nodeA, int nodeB) {
    if (nodeA < nodeCount && nodeB < nodeCount) {
        network[nodeA].connections[network[nodeA].connectionCount++] = nodeB;
        network[nodeB].connections[network[nodeB].connectionCount++] = nodeA; // Assuming bidirectional
        printf("Connection established between %s and %s.\n", network[nodeA].name, network[nodeB].name);
    } else {
        printf("Invalid node ID(s) for connection.\n");
    }
}

void displayNetwork() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %d (%s):", network[i].id, network[i].name);
        for (int j = 0; j < network[i].connectionCount; j++) {
            printf(" %d (%s)", network[i].connections[j], network[network[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    char name[30];
    int choice, nodeA, nodeB;

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name);
                addNode(name);
                break;
            case 2:
                printf("Enter two node IDs to connect (e.g., 0 1): ");
                scanf("%d %d", &nodeA, &nodeB);
                addConnection(nodeA, nodeB);
                break;
            case 3:
                displayNetwork();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}