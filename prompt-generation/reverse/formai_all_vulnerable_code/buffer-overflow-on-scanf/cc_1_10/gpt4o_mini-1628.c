//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

Node* nodes[MAX_NODES];
int nodeCount = 0;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

void addNode(const char* name) {
    if (nodeCount >= MAX_NODES) {
        printf("Maximum nodes limit reached! Can't add more nodes.\n");
        return;
    }
    nodes[nodeCount++] = createNode(name);
    printf("Node '%s' added.\n", name);
}

void addConnection(const char* name1, const char* name2) {
    Node *node1 = NULL, *node2 = NULL;

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i]->name, name1) == 0) {
            node1 = nodes[i];
        }
        if (strcmp(nodes[i]->name, name2) == 0) {
            node2 = nodes[i];
        }
    }

    if (node1 && node2) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1; // Undirected connection
        printf("Connection added between '%s' and '%s'.\n", name1, name2);
    } else {
        printf("One or both nodes not found!\n");
    }
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%s is connected to:", nodes[i]->name);
        for (int j = 0; j < nodes[i]->connectionCount; j++) {
            printf(" %s,", nodes[i]->connections[j]->name);
        }
        printf("\b \n"); // To remove the last comma
    }
}

void freeMemory() {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    do {
        printf("\n1. Add Node\n2. Add Connection\n3. Display Topology\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name1);
                addNode(name1);
                break;
            case 2:
                printf("Enter first node name: ");
                scanf("%s", name1);
                printf("Enter second node name: ");
                scanf("%s", name2);
                addConnection(name1, name2);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                freeMemory();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}