//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct {
    int id;
    char name[20];
    int x, y;
    int links[MAX_LINKS];
    int num_links;
} Node;

void add_link(Node* node1, Node* node2) {
    node1->links[node1->num_links++] = node2->id;
    node2->links[node2->num_links++] = node1->id;
}

void print_node(Node* node) {
    printf("Node %d (%s) at (%d,%d)\n", node->id, node->name, node->x, node->y);
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;

    Node* node1 = &nodes[num_nodes++];
    strcpy(node1->name, "Node 1");
    node1->id = 1;
    node1->x = 0;
    node1->y = 0;

    Node* node2 = &nodes[num_nodes++];
    strcpy(node2->name, "Node 2");
    node2->id = 2;
    node2->x = 50;
    node2->y = 0;

    Node* node3 = &nodes[num_nodes++];
    strcpy(node3->name, "Node 3");
    node3->id = 3;
    node3->x = 100;
    node3->y = 0;

    add_link(node1, node2);
    add_link(node2, node3);

    for (int i = 0; i < num_nodes; i++) {
        print_node(&nodes[i]);
    }

    return 0;
}