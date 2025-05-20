//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

int num_nodes = 0;
int num_edges = 0;

void add_node(int id) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    nodes[num_nodes].id = id;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = malloc(MAX_EDGES * sizeof(int));
    memset(nodes[num_nodes].neighbors, -1, MAX_EDGES * sizeof(int));
    num_nodes++;
}

void add_edge(int from, int to) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    num_edges++;
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].degree; j++) {
            int neighbor = nodes[i].neighbors[j];
            printf("%d ", neighbor);
        }
        printf("\n");
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

    print_graph();

    return 0;
}