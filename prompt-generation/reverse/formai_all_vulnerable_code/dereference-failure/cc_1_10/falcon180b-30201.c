//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 100

// Node structure
typedef struct {
    int id;
    char name[20];
    int num_links;
    int* link_nodes; // Array of linked nodes
} Node;

// Function to create a new node
Node* create_node(int id, char* name) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->num_links = 0;
    new_node->link_nodes = NULL;
    return new_node;
}

// Function to create a new link between two nodes
void create_link(Node* node1, Node* node2) {
    node1->num_links++;
    node1->link_nodes = realloc(node1->link_nodes, sizeof(int) * node1->num_links);
    if (node1->link_nodes == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    node1->link_nodes[node1->num_links - 1] = node2->id;
    node2->num_links++;
    node2->link_nodes = realloc(node2->link_nodes, sizeof(int) * node2->num_links);
    if (node2->link_nodes == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    node2->link_nodes[node2->num_links - 1] = node1->id;
}

// Function to print the network topology
void print_topology(Node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        printf("Links: ");
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf("%d ", nodes[i].link_nodes[j]);
        }
        printf("\n");
    }
}

int main() {
    Node* nodes = malloc(sizeof(Node) * MAX_NODES);
    if (nodes == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    int num_nodes = 0;

    // Create nodes
    Node* node1 = create_node(1, "Node 1");
    Node* node2 = create_node(2, "Node 2");
    Node* node3 = create_node(3, "Node 3");
    Node* node4 = create_node(4, "Node 4");

    // Link nodes
    create_link(node1, node2);
    create_link(node2, node3);
    create_link(node3, node4);
    create_link(node4, node1);

    // Print network topology
    print_topology(nodes, num_nodes);

    return 0;
}