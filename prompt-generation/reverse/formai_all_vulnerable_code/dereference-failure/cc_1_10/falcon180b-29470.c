//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_LINKS 10000

typedef struct {
    int id;
    double x, y;
} Node;

typedef struct {
    int id;
    Node *node1, *node2;
    double weight;
} Link;

int num_nodes = 0;
Node *nodes;
int num_links = 0;
Link *links;

void add_node(double x, double y) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->id = num_nodes++;
    new_node->x = x;
    new_node->y = y;
    nodes = (Node*)realloc(nodes, sizeof(Node) * num_nodes);
    nodes[num_nodes - 1] = *new_node;
}

void add_link(int node1_id, int node2_id, double weight) {
    Node *node1 = &nodes[node1_id];
    Node *node2 = &nodes[node2_id];
    Link *new_link = (Link*)malloc(sizeof(Link));
    new_link->id = num_links++;
    new_link->node1 = node1;
    new_link->node2 = node2;
    new_link->weight = weight;
    links = (Link*)realloc(links, sizeof(Link) * num_links);
    links[num_links - 1] = *new_link;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: (%f, %f)\n", nodes[i].id, nodes[i].x, nodes[i].y);
    }
}

void print_links() {
    for (int i = 0; i < num_links; i++) {
        printf("Link %d: (%d, %d), weight = %f\n", links[i].id, links[i].node1->id, links[i].node2->id, links[i].weight);
    }
}

int main() {
    add_node(0, 0);
    add_node(1, 1);
    add_node(2, 2);
    add_node(3, 3);
    add_link(0, 1, 1.0);
    add_link(1, 2, 1.0);
    add_link(2, 3, 1.0);
    add_link(3, 0, 1.0);
    print_nodes();
    print_links();
    return 0;
}