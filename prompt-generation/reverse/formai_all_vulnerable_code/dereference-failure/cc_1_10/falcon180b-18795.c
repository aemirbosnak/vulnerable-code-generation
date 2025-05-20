//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

typedef struct node {
    int id;
    char *label;
    int degree;
    int *neighbors;
} Node;

typedef struct edge {
    int weight;
    Node *src;
    Node *dest;
} Edge;

Node *nodes;
Edge *edges;
int num_nodes, num_edges;

void init() {
    nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    num_nodes = 0;
    num_edges = 0;
}

void add_node(int id, char *label) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes exceeded.\n");
        exit(1);
    }
    nodes[num_nodes].id = id;
    nodes[num_nodes].label = strdup(label);
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = (int *)malloc(MAX_NODES * sizeof(int));
    num_nodes++;
}

void add_edge(int src_id, int dest_id, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges exceeded.\n");
        exit(1);
    }
    edges[num_edges].weight = weight;
    edges[num_edges].src = &nodes[src_id];
    edges[num_edges].dest = &nodes[dest_id];
    nodes[src_id].degree++;
    nodes[dest_id].degree++;
    num_edges++;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].label);
        for (int j = 0; j < nodes[i].degree; j++) {
            printf(" -> Node %d (%d)\n", nodes[i].neighbors[j], edges[j].weight);
        }
    }
}

int main() {
    init();
    add_node(1, "A");
    add_node(2, "B");
    add_node(3, "C");
    add_node(4, "D");
    add_edge(1, 2, 5);
    add_edge(2, 3, 3);
    add_edge(3, 4, 2);
    print_graph();
    return 0;
}