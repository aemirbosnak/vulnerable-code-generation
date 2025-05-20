//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name[20];
    int id;
    int degree;
    int *neighbors;
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
    Node new_node;
    strcpy(new_node.name, name);
    new_node.id = num_nodes;
    new_node.degree = 0;
    new_node.neighbors = malloc(MAX_EDGES * sizeof(int));
    memset(new_node.neighbors, -1, MAX_EDGES * sizeof(int));
    nodes[num_nodes++] = new_node;
}

void add_edge(int src, int dest, int weight) {
    Edge new_edge;
    new_edge.src = src;
    new_edge.dest = dest;
    new_edge.weight = weight;
    edges[num_edges++] = new_edge;
    nodes[src - 1].degree++;
    nodes[dest - 1].degree++;
}

void print_node(Node node) {
    printf("Node %d: %s\n", node.id, node.name);
}

void print_edge(Edge edge) {
    printf("Edge %d: (%d, %d, %d)\n", edge.src, edge.dest, edge.weight);
}

void print_graph() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
    }
    for (i = 0; i < num_edges; i++) {
        print_edge(edges[i]);
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");
    add_edge(1, 2, 5);
    add_edge(1, 3, 10);
    add_edge(2, 4, 15);
    add_edge(3, 4, 20);
    add_edge(3, 5, 25);
    print_graph();
    return 0;
}