//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct {
    char name[20];
    int numConnections;
    int connections[MAX_CONNECTIONS];
} Node;

Node network[MAX_NODES];
int nodeCount = 0;

void addNode(const char *name) {
    if (nodeCount < MAX_NODES) {
        strncpy(network[nodeCount].name, name, 20);
        network[nodeCount].numConnections = 0;
        nodeCount++;
    } else {
        printf("Max node limit reached.\n");
    }
}

void addConnection(int from, int to) {
    if (from < nodeCount && to < nodeCount) {
        if (network[from].numConnections < MAX_CONNECTIONS) {
            network[from].connections[network[from].numConnections++] = to;
        } else {
            printf("Max connections reached for node %s.\n", network[from].name);
        }
        // You can uncomment the below lines to add bi-directional connection
        // if (network[to].numConnections < MAX_CONNECTIONS) {
        //     network[to].connections[network[to].numConnections++] = from;
        // }
    } else {
        printf("Invalid node index.\n");
    }
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %s:\n", network[i].name);
        if (network[i].numConnections > 0) {
            printf("  Connections: ");
            for (int j = 0; j < network[i].numConnections; j++) {
                printf("%s ", network[network[i].connections[j]].name);
            }
            printf("\n");
        } else {
            printf("  No connections.\n");
        }
    }
}

int main() {
    int choice, from, to;
    char name[20];

    printf("Welcome to the Network Topology Mapper!\n");

    while (1) {
        printf("\n1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name);
                addNode(name);
                break;
            case 2:
                printf("Enter from node index (0 to %d): ", nodeCount - 1);
                scanf("%d", &from);
                printf("Enter to node index (0 to %d): ", nodeCount - 1);
                scanf("%d", &to);
                addConnection(from, to);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}