//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

void addConnection(Node* node1, Node* node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1; // For undirected connection
    } else {
        printf("Connection limit reached for one of the nodes.\n");
    }
}

void displayTopology(Node* nodes[], int nodeCount) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node: %s\n", nodes[i]->name);
        printf("Connections: ");
        for (int j = 0; j < nodes[i]->connectionCount; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n\n");
    }
}

void freeNetwork(Node* nodes[], int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

int getUserChoice() {
    int choice;
    printf("1. Add Node\n");
    printf("2. Add Connection\n");
    printf("3. Display Topology\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Node* nodes[MAX_NODES];
    int nodeCount = 0;
    int running = 1;

    while (running) {
        int choice = getUserChoice();

        switch (choice) {
            case 1: {
                if (nodeCount < MAX_NODES) {
                    char name[MAX_NAME_LENGTH];
                    printf("Enter node name: ");
                    scanf("%s", name);
                    nodes[nodeCount++] = createNode(name);
                } else {
                    printf("Maximum nodes reached.\n");
                }
                break;
            }
            case 2: {
                if (nodeCount < 2) {
                    printf("Need at least two nodes to create a connection.\n");
                } else {
                    int nodeIndex1, nodeIndex2;
                    printf("Enter index of first node (0 to %d): ", nodeCount - 1);
                    scanf("%d", &nodeIndex1);
                    printf("Enter index of second node (0 to %d): ", nodeCount - 1);
                    scanf("%d", &nodeIndex2);

                    if (nodeIndex1 >= 0 && nodeIndex1 < nodeCount && nodeIndex2 >= 0 && nodeIndex2 < nodeCount) {
                        addConnection(nodes[nodeIndex1], nodes[nodeIndex2]);
                    } else {
                        printf("Invalid node indices.\n");
                    }
                }
                break;
            }
            case 3: {
                displayTopology(nodes, nodeCount);
                break;
            }
            case 4: {
                freeNetwork(nodes, nodeCount);
                running = 0;
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}