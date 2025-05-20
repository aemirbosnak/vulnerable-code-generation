//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

// Node structure
typedef struct node {
    char name[20];
    int id;
    int degree;
    struct node *links[MAX_LINKS];
} Node;

// Function to create a new node
Node* newNode(char *name, int id) {
    Node *node = (Node*) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = id;
    node->degree = 0;
    for (int i = 0; i < MAX_LINKS; i++) {
        node->links[i] = NULL;
    }
    return node;
}

// Function to connect two nodes
void connectNodes(Node *node1, Node *node2) {
    node1->degree++;
    node2->degree++;
    node1->links[node1->degree - 1] = node2;
    node2->links[node2->degree - 1] = node1;
}

// Function to print the network topology
void printTopology(Node *node) {
    printf("Node %s (%d) has %d links:\n", node->name, node->id, node->degree);
    for (int i = 0; i < node->degree; i++) {
        printf("- %s (%d)\n", ((Node*) node->links[i])->name, ((Node*) node->links[i])->id);
    }
}

// Main function
int main() {
    // Create nodes
    Node *node1 = newNode("Kingdom A", 1);
    Node *node2 = newNode("Kingdom B", 2);
    Node *node3 = newNode("Kingdom C", 3);

    // Connect nodes
    connectNodes(node1, node2);
    connectNodes(node1, node3);
    connectNodes(node2, node3);

    // Print network topology
    printf("Network Topology:\n");
    printTopology(node1);
    printTopology(node2);
    printTopology(node3);

    return 0;
}