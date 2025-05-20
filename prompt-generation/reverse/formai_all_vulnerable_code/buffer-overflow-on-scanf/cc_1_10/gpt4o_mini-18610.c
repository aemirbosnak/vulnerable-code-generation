//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct Node {
    int id;
    char name[50];
    struct Node* connections[MAX_CONNECTIONS];
    int connectionCount;
} Node;

Node* nodes[MAX_NODES];
int nodeCount = 0;

Node* createNode(int id, const char* name);
void addNode(int id, const char* name);
void connectNodes(int id1, int id2);
void printNetworkTopology();
void freeNetwork();

int main() {
    int choice, id1, id2;
    char name[50];

    while(1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Connect Nodes\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter Node ID: ");
                scanf("%d", &id1);
                printf("Enter Node Name: ");
                scanf("%s", name);
                addNode(id1, name);
                break;
            case 2:
                printf("Enter ID of Node 1: ");
                scanf("%d", &id1);
                printf("Enter ID of Node 2: ");
                scanf("%d", &id2);
                connectNodes(id1, id2);
                break;
            case 3:
                printNetworkTopology();
                break;
            case 4:
                freeNetwork();
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->connectionCount = 0;
    return newNode;
}

void addNode(int id, const char* name) {
    if (nodeCount >= MAX_NODES) {
        printf("Maximum number of nodes reached.\n");
        return;
    }
    if (id < 0 || id >= MAX_NODES) {
        printf("Invalid node ID.\n");
        return;
    }
    nodes[nodeCount++] = createNode(id, name);
    printf("Node %s with ID %d added.\n", name, id);
}

void connectNodes(int id1, int id2) {
    Node* node1 = NULL;
    Node* node2 = NULL;

    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i]->id == id1) node1 = nodes[i];
        if (nodes[i]->id == id2) node2 = nodes[i];
    }

    if (!node1 || !node2) {
        printf("One of the nodes does not exist.\n");
        return;
    }

    if (node1->connectionCount >= MAX_CONNECTIONS || node2->connectionCount >= MAX_CONNECTIONS) {
        printf("Maximum connections reached for one of the nodes.\n");
        return;
    }

    node1->connections[node1->connectionCount++] = node2;
    node2->connections[node2->connectionCount++] = node1; // Bi-directional connection
    printf("Connected Node %d to Node %d.\n", id1, id2);
}

void printNetworkTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        Node* node = nodes[i];
        printf("Node %d (%s): ", node->id, node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%d ", node->connections[j]->id);
        }
        printf("\n");
    }
}

void freeNetwork() {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
    printf("Network memory freed.\n");
}