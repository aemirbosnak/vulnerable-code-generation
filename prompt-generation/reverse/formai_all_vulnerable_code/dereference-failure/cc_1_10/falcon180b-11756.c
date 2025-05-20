//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int source;
    int target;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(int id) {
    nodes[num_nodes].id = id;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = (int *)malloc(sizeof(int));
    num_nodes++;
}

void add_edge(int source, int target) {
    edges[num_edges].source = source;
    edges[num_edges].target = target;
    num_edges++;
}

void print_node(Node node) {
    printf("Node %d (degree %d): ", node.id, node.degree);
    for (int i = 0; i < node.degree; i++) {
        printf("%d ", node.neighbors[i]);
    }
    printf("\n");
}

void print_edge(Edge edge) {
    printf("Edge from %d to %d\n", edge.source, edge.target);
}

void print_network() {
    for (int i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
    }
    for (int i = 0; i < num_edges; i++) {
        print_edge(edges[i]);
    }
}

int main() {
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);

    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 5);

    print_network();

    return 0;
}