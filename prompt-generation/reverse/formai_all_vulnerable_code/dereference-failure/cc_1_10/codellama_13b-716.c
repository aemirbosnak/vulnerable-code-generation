//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int id;
    char name[100];
} node_t;

typedef struct {
    int src;
    int dest;
    int weight;
} edge_t;

typedef struct {
    node_t nodes[MAX_NODES];
    edge_t edges[MAX_EDGES];
    int num_nodes;
    int num_edges;
} graph_t;

void add_node(graph_t *g, int id, char *name) {
    if (g->num_nodes == MAX_NODES) {
        printf("Graph is full, unable to add node\n");
        return;
    }
    g->nodes[g->num_nodes].id = id;
    strcpy(g->nodes[g->num_nodes].name, name);
    g->num_nodes++;
}

void add_edge(graph_t *g, int src, int dest, int weight) {
    if (g->num_edges == MAX_EDGES) {
        printf("Graph is full, unable to add edge\n");
        return;
    }
    g->edges[g->num_edges].src = src;
    g->edges[g->num_edges].dest = dest;
    g->edges[g->num_edges].weight = weight;
    g->num_edges++;
}

void print_graph(graph_t *g) {
    printf("Nodes: ");
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%s ", g->nodes[i].name);
    }
    printf("\n");
    printf("Edges: ");
    for (int i = 0; i < g->num_edges; i++) {
        printf("(%d, %d) ", g->edges[i].src, g->edges[i].dest);
    }
    printf("\n");
}

int main() {
    graph_t *g = malloc(sizeof(graph_t));
    g->num_nodes = 0;
    g->num_edges = 0;

    add_node(g, 1, "Node 1");
    add_node(g, 2, "Node 2");
    add_node(g, 3, "Node 3");

    add_edge(g, 1, 2, 10);
    add_edge(g, 1, 3, 5);
    add_edge(g, 2, 3, 20);

    print_graph(g);

    free(g);
    return 0;
}