//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connectionCount;
} Node;

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

void addConnection(Node* nodeA, Node* nodeB) {
    if (nodeA->connectionCount < MAX_NODES && nodeB->connectionCount < MAX_NODES) {
        nodeA->connections[nodeA->connectionCount++] = nodeB;
        nodeB->connections[nodeB->connectionCount++] = nodeA; // Bidirectional connection
    } else {
        printf("Error: Maximum connections reached for nodes %s and %s.\n", nodeA->name, nodeB->name);
    }
}

void displayTopology(Node* nodes[], int nodeCount) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        Node* currentNode = nodes[i];
        printf("Node %d (%s): ", currentNode->id, currentNode->name);
        for (int j = 0; j < currentNode->connectionCount; j++) {
            printf("%s ", currentNode->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Node* nodes[], int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int nodeCount = 0;

    int choice;
    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (nodeCount >= MAX_NODES) {
                printf("Maximum nodes reached! Cannot add more nodes.\n");
                continue;
            }

            int id;
            char name[MAX_NAME_LENGTH];
            printf("Enter Node ID: ");
            scanf("%d", &id);
            printf("Enter Node Name: ");
            scanf("%s", name);
            nodes[nodeCount++] = createNode(id, name);
            printf("Node %s added successfully!\n", name);

        } else if (choice == 2) {
            int idA, idB;
            printf("Enter ID of first node: ");
            scanf("%d", &idA);
            printf("Enter ID of second node: ");
            scanf("%d", &idB);

            Node *nodeA = NULL, *nodeB = NULL;
            for (int i = 0; i < nodeCount; i++) {
                if (nodes[i]->id == idA) nodeA = nodes[i];
                if (nodes[i]->id == idB) nodeB = nodes[i];
            }

            if (nodeA && nodeB) {
                addConnection(nodeA, nodeB);
                printf("Connection added between %s and %s.\n", nodeA->name, nodeB->name);
            } else {
                printf("Error: One or both node IDs not found.\n");
            }

        } else if (choice == 3) {
            displayTopology(nodes, nodeCount);
        } else if (choice == 4) {
            freeNetwork(nodes, nodeCount);
            printf("Exiting program. Memory freed.\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}