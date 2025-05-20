//Falcon-180B DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    int degree;
    int *edges;
} node_t;

typedef struct graph {
    int n;
    node_t *nodes;
} graph_t;

graph_t *create_graph() {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->n = 0;
    graph->nodes = (node_t *)malloc(MAX_NODES * sizeof(node_t));
    return graph;
}

void add_node(graph_t *graph, int id) {
    graph->nodes[graph->n].id = id;
    graph->nodes[graph->n].degree = 0;
    graph->nodes[graph->n].edges = (int *)malloc(MAX_EDGES * sizeof(int));
    graph->n++;
}

void add_edge(graph_t *graph, int from, int to) {
    graph->nodes[from].degree++;
    graph->nodes[to].degree++;
    graph->nodes[from].edges[graph->nodes[from].degree - 1] = to;
    graph->nodes[to].edges[graph->nodes[to].degree - 1] = from;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->n; i++) {
        printf("Node %d: ", graph->nodes[i].id);
        for (int j = 0; j < graph->nodes[i].degree; j++) {
            printf("%d ", graph->nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    graph_t *graph = create_graph();
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 1);
    print_graph(graph);
    return 0;
}