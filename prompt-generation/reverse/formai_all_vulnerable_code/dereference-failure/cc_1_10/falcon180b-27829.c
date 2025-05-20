//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct edge {
    int u, v, cost;
};

struct node {
    int id;
    int degree;
    struct edge *adj;
};

struct node *create_node(int id) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->id = id;
    node->degree = 0;
    node->adj = NULL;
    return node;
}

void add_edge(struct node *graph, int u, int v, int cost) {
    struct edge *edge = (struct edge *)malloc(sizeof(struct edge));
    edge->u = u;
    edge->v = v;
    edge->cost = cost;
    graph->adj = (struct edge *)realloc(graph->adj, (graph->degree + 1) * sizeof(struct edge));
    graph->adj[graph->degree] = *edge;
    graph->degree++;
}

void print_graph(struct node *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->degree; i++) {
        printf("%d - %d: %d\n", graph->adj[i].u, graph->adj[i].v, graph->adj[i].cost);
    }
}

int main() {
    struct node *graph = create_node(1);
    add_edge(graph, 1, 2, 5);
    add_edge(graph, 1, 4, 10);
    add_edge(graph, 2, 3, 4);
    add_edge(graph, 3, 4, 6);
    add_edge(graph, 4, 5, 2);
    add_edge(graph, 5, 6, 8);

    print_graph(graph);

    return 0;
}