//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct Node {
    char name[20];
    int id;
} Node;

typedef struct Edge {
    Node* from;
    Node* to;
} Edge;

Node* nodes[MAX_NODES];
int num_nodes = 0;

Edge* edges[MAX_EDGES];
int num_edges = 0;

void add_node(char* name) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = num_nodes++;
    nodes[num_nodes - 1] = new_node;
}

void add_edge(char* from_name, char* to_name) {
    Node* from_node = NULL;
    Node* to_node = NULL;

    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i]->name, from_name) == 0) {
            from_node = nodes[i];
        }
        if (strcmp(nodes[i]->name, to_name) == 0) {
            to_node = nodes[i];
        }
    }

    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->from = from_node;
    new_edge->to = to_node;
    edges[num_edges++] = new_edge;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", nodes[i]->id, nodes[i]->name);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d\n", edges[i]->from->id, edges[i]->to->id);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_node("Node 4");
    add_node("Node 5");

    add_edge("Node 1", "Node 2");
    add_edge("Node 2", "Node 3");
    add_edge("Node 3", "Node 4");
    add_edge("Node 4", "Node 5");

    print_nodes();
    print_edges();

    return 0;
}