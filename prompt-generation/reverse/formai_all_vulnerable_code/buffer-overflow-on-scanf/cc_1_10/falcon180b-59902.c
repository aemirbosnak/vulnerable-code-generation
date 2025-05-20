//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node;
    int weight;
    struct node_edge *next;
} node_edge;

typedef struct {
    int num_nodes;
    int num_edges;
    node_edge *edges;
} graph;

graph *create_graph() {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = 0;
    g->num_edges = 0;
    g->edges = NULL;
    return g;
}

void add_node(graph *g) {
    g->num_nodes++;
    printf("Enter node name: ");
    scanf("%d", &g->edges[g->num_edges].node);
    g->edges[g->num_edges++].weight = rand() % 10;
}

void add_edge(graph *g) {
    int from, to;
    printf("Enter start node: ");
    scanf("%d", &from);
    printf("Enter end node: ");
    scanf("%d", &to);
    node_edge *e = (node_edge *)malloc(sizeof(node_edge));
    e->node = to;
    e->weight = rand() % 10;
    e->next = g->edges[from].next;
    g->edges[from].next = e;
    g->num_edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("Node %d: ", i);
        node_edge *e = g->edges[i].next;
        while (e!= NULL) {
            printf("(%d, %d) ", e->node, e->weight);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    graph *g = create_graph();
    add_node(g);
    add_node(g);
    add_edge(g);
    add_edge(g);
    print_graph(g);
    return 0;
}