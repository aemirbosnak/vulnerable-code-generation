//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

typedef struct Node {
    char name[20];
    struct Node *connections[MAX_NODES];
    int conn_count;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->conn_count = 0;
    return newNode;
}

void connectNodes(Node* node1, Node* node2) {
    if (node1->conn_count < MAX_NODES && node2->conn_count < MAX_NODES) {
        node1->connections[node1->conn_count++] = node2;
        node2->connections[node2->conn_count++] = node1; // bi-directional connection
    } else {
        printf("Error: Maximum connections reached for %s or %s.\n", node1->name, node2->name);
    }
}

void displayNetwork(Node* nodes[], int count) {
    printf("Network Topology:\n");
    for (int i = 0; i < count; i++) {
        printf("Device: %s is connected to: ", nodes[i]->name);
        for (int j = 0; j < nodes[i]->conn_count; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

void freeNetwork(Node* nodes[], int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int nodeCount = 0;
    char name[20];
    char action[10];

    while (1) {
        printf("Welcome to the Network Topology Mapper\n");
        printf("Choose an action: add, connect, display, exit\n");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            if (nodeCount >= MAX_NODES) {
                printf("Maximum nodes reached. Unable to add more devices.\n");
                continue;
            }
            printf("Enter device name: ");
            scanf("%s", name);
            nodes[nodeCount++] = createNode(name);
            printf("Device %s added to the network.\n", name);

        } else if (strcmp(action, "connect") == 0) {
            char name1[20], name2[20];
            printf("Enter the names of the two devices to connect: ");
            scanf("%s %s", name1, name2);

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
                connectNodes(node1, node2);
                printf("%s successfully connected to %s.\n", name1, name2);
            } else {
                printf("Error: One or both devices not found in the network.\n");
            }

        } else if (strcmp(action, "display") == 0) {
            displayNetwork(nodes, nodeCount);

        } else if (strcmp(action, "exit") == 0) {
            printf("Exiting the program.\n");
            break;

        } else {
            printf("Invalid action. Please try again.\n");
        }
    }

    freeNetwork(nodes, nodeCount);
    return 0;
}