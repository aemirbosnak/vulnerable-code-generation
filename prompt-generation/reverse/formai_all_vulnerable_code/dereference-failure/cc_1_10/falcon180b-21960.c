//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 10000
#define MAX_EDGES 20000

typedef struct {
    int id;
    double value;
    int type;
    int node1;
    int node2;
} Component;

typedef struct {
    int id;
    double value;
    int type;
} Node;

typedef struct {
    int start;
    int end;
    double resistance;
} Edge;

int num_components = 0;
int num_nodes = 0;
int num_edges = 0;

Component *components = NULL;
Node *nodes = NULL;
Edge *edges = NULL;

void add_component(int id, double value, int type) {
    if (num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        exit(1);
    }

    components = realloc(components, sizeof(Component) * ++num_components);
    components[num_components - 1].id = id;
    components[num_components - 1].value = value;
    components[num_components - 1].type = type;
}

void add_node(int id, double value, int type) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }

    nodes = realloc(nodes, sizeof(Node) * ++num_nodes);
    nodes[num_nodes - 1].id = id;
    nodes[num_nodes - 1].value = value;
    nodes[num_nodes - 1].type = type;
}

void add_edge(int start, int end, double resistance) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }

    edges = realloc(edges, sizeof(Edge) * ++num_edges);
    edges[num_edges - 1].start = start;
    edges[num_edges - 1].end = end;
    edges[num_edges - 1].resistance = resistance;
}

int main() {
    add_component(1, 10.0, 0);
    add_component(2, 20.0, 1);
    add_node(3, 0.0, 0);
    add_node(4, 0.0, 1);

    add_edge(1, 3, 1.0);
    add_edge(2, 4, 2.0);

    return 0;
}