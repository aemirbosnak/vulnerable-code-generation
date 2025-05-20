//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct node {
    char name[32];
    int id;
    int num_links;
    struct link *links[MAX_LINKS];
} Node;

typedef struct link {
    Node *node1;
    Node *node2;
    int cost;
} Link;

Node *nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = num_nodes++;
    node->num_links = 0;
    for (int i = 0; i < MAX_LINKS; i++) {
        node->links[i] = NULL;
    }
    nodes[num_nodes - 1] = node;
}

void add_link(Node *node1, Node *node2, int cost) {
    Link *link = malloc(sizeof(Link));
    link->node1 = node1;
    link->node2 = node2;
    link->cost = cost;
    node1->num_links++;
    node1->links[node1->num_links - 1] = link;
}

void print_node(Node *node) {
    printf("Node: %s (%d)\n", node->name, node->id);
}

void print_link(Link *link) {
    printf("Link: %s -> %s (%d)\n", link->node1->name, link->node2->name, link->cost);
}

void print_network() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i);
        print_node(nodes[i]);
        printf("\n");
        for (int j = 0; j < nodes[i]->num_links; j++) {
            print_link(nodes[i]->links[j]);
        }
        printf("\n");
    }
}

int main() {
    add_node("Node A");
    add_node("Node B");
    add_node("Node C");
    add_node("Node D");
    add_node("Node E");

    add_link(nodes[0], nodes[1], 10);
    add_link(nodes[1], nodes[2], 20);
    add_link(nodes[2], nodes[3], 30);
    add_link(nodes[3], nodes[4], 40);

    print_network();

    return 0;
}