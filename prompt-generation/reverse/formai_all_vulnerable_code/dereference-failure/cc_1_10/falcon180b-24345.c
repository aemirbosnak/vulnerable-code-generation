//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char *name;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes exceeded.\n");
        exit(1);
    }
    Node node = {num_nodes++, strdup(name)};
    nodes[num_nodes - 1] = node;
}

int get_node_id(char *name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_edge(int src, int dest, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges exceeded.\n");
        exit(1);
    }
    Edge edge = {src, dest, weight};
    edges[num_edges++] = edge;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (weight: %d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_edge(0, 1, 10);
    add_edge(1, 2, 20);
    print_nodes();
    print_edges();
    return 0;
}