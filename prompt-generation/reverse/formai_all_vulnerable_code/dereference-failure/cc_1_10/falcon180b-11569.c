//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 1000
#define MAX_EDGE_COUNT 2000

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

typedef struct Node {
    int id;
    int degree;
    Edge *edges;
} Node;

void add_edge(Node *graph, int from, int to, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    graph->edges = (Edge *)realloc(graph->edges, sizeof(Edge) * (graph->degree + 1));
    graph->edges[graph->degree] = *new_edge;
    graph->degree++;
}

void print_graph(Node *graph) {
    int i;
    for (i = 0; i < graph->degree; i++) {
        printf("(%d,%d,%d) ", graph->edges[i].from, graph->edges[i].to, graph->edges[i].weight);
    }
}

int main() {
    Node graph;
    graph.id = 1;
    graph.degree = 0;
    graph.edges = (Edge *)malloc(sizeof(Edge));

    add_edge(&graph, 1, 2, 3);
    add_edge(&graph, 1, 3, 4);
    add_edge(&graph, 2, 4, 5);
    add_edge(&graph, 3, 4, 1);

    print_graph(&graph);

    return 0;
}