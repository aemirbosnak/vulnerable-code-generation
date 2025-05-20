//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct {
    char name[10];
    int id;
    int links[MAX_LINKS];
    int num_links;
} Node;

void add_link(Node* node1, Node* node2) {
    node1->links[node1->num_links++] = node2->id;
    node2->links[node2->num_links++] = node1->id;
}

void print_node(Node* node) {
    printf("Node: %s, ID: %d, Links: ", node->name, node->id);
    for (int i = 0; i < node->num_links; i++) {
        printf("%d ", node->links[i]);
    }
    printf("\n");
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;

    // Create nodes
    Node* node1 = &nodes[num_nodes++];
    strcpy(node1->name, "Node1");
    node1->id = 1;

    Node* node2 = &nodes[num_nodes++];
    strcpy(node2->name, "Node2");
    node2->id = 2;

    Node* node3 = &nodes[num_nodes++];
    strcpy(node3->name, "Node3");
    node3->id = 3;

    // Connect nodes
    add_link(node1, node2);
    add_link(node2, node3);
    add_link(node3, node1);

    // Print nodes and links
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        print_node(&nodes[i]);
    }

    return 0;
}