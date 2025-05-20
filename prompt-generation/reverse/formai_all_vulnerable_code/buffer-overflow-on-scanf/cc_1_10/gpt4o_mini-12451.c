//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
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

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->connectionCount = 0;
    return newNode;
}

void addConnection(Node* node1, Node* node2) {
    if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1; // Bi-directional
        printf("Connection added between %s and %s.\n", node1->name, node2->name);
    } else {
        printf("Max connections reached for either %s or %s.\n", node1->name, node2->name);
    }
}

void displayTopology(Node* nodes[], int nodeCount) {
    printf("\n=== Network Topology ===\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %s is connected to: ", nodes[i]->name);
        for (int j = 0; j < nodes[i]->connectionCount; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int nodeCount = 0;
    char command[50];

    printf("Welcome to the Network Topology Mapper!\n");
    while (1) {
        printf("\nPlease enter a command (add_node, connect, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add_node") == 0) {
            if (nodeCount >= MAX_NODES) {
                printf("Max nodes reached. Cannot add more nodes.\n");
                continue;
            }
            printf("Enter node name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            nodes[nodeCount++] = createNode(name);
            printf("Node %s added.\n", name);
        } 
        else if (strcmp(command, "connect") == 0) {
            if (nodeCount < 2) {
                printf("At least two nodes are required to connect.\n");
                continue;
            }
            printf("Enter the names of the two nodes to connect (separated by space): ");
            char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
            scanf("%s %s", name1, name2);
            Node* node1 = NULL;
            Node* node2 = NULL;

            for (int i = 0; i < nodeCount; i++) {
                if (strcmp(nodes[i]->name, name1) == 0) {
                    node1 = nodes[i];
                }
                if (strcmp(nodes[i]->name, name2) == 0) {
                    node2 = nodes[i];
                }
            }

            if (node1 && node2) {
                addConnection(node1, node2);
            } else {
                printf("One or both nodes not found. Please check the names.\n");
            }
        } 
        else if (strcmp(command, "display") == 0) {
            displayTopology(nodes, nodeCount);
        } 
        else if (strcmp(command, "exit") == 0) {
            break;
        } 
        else {
            printf("Unknown command. Please try again.\n");
        }
    }

    // Free allocated nodes
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }

    printf("Exiting the Network Topology Mapper. Bye!\n");
    return 0;
}