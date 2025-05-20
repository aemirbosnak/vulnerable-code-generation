//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 1000000

typedef struct node {
    int id;
    int degree;
    int *adj_list;
} Node;

typedef struct graph {
    Node *nodes;
    int n_nodes;
    int n_edges;
} Graph;

Graph *create_graph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    g->n_nodes = 0;
    g->n_edges = 0;
    return g;
}

void add_node(Graph *g, int id) {
    Node *n = &g->nodes[g->n_nodes++];
    n->id = id;
    n->degree = 0;
    n->adj_list = (int *)malloc(MAX_EDGES * sizeof(int));
}

void add_edge(Graph *g, int from, int to) {
    Node *u = &g->nodes[from];
    Node *v = &g->nodes[to];
    int *adj_list = v->adj_list;
    int i, j;
    for (i = 0; i < v->degree; i++) {
        if (adj_list[i] == from) {
            return;
        }
    }
    adj_list[v->degree++] = from;
    u->degree++;
    g->n_edges++;
}

void print_graph(Graph *g) {
    int i, j;
    for (i = 0; i < g->n_nodes; i++) {
        printf("%d: ", g->nodes[i].id);
        for (j = 0; j < g->nodes[i].degree; j++) {
            printf("%d ", g->nodes[i].adj_list[j]);
        }
        printf("\n");
    }
}

void free_graph(Graph *g) {
    int i;
    for (i = 0; i < g->n_nodes; i++) {
        free(g->nodes[i].adj_list);
    }
    free(g->nodes);
    free(g);
}

int main() {
    Graph *g = create_graph();
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_node(g, 4);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    add_edge(g, 4, 1);
    print_graph(g);
    free_graph(g);
    return 0;
}