//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct node {
    int index;
    int degree;
    int *adj_list;
} Node;

typedef struct graph {
    int n_nodes;
    int n_edges;
    Node *nodes;
} Graph;

Graph* create_graph() {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n_nodes = 0;
    g->n_edges = 0;
    g->nodes = NULL;
    return g;
}

void add_node(Graph *g, int index) {
    g->nodes = (Node*)realloc(g->nodes, sizeof(Node) * (g->n_nodes + 1));
    g->nodes[g->n_nodes].index = index;
    g->nodes[g->n_nodes].degree = 0;
    g->nodes[g->n_nodes].adj_list = NULL;
    g->n_nodes++;
}

void add_edge(Graph *g, int u, int v) {
    g->nodes[u].degree++;
    g->nodes[v].degree++;
    g->nodes[u].adj_list = (int*)realloc(g->nodes[u].adj_list, sizeof(int) * (g->nodes[u].degree + 1));
    g->nodes[u].adj_list[g->nodes[u].degree - 1] = v;
    g->n_edges++;
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->n_nodes; i++) {
        printf("Node %d: ", g->nodes[i].index);
        for (int j = 0; j < g->nodes[i].degree; j++) {
            printf("%d ", g->nodes[i].adj_list[j]);
        }
        printf("\n");
    }
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
    return 0;
}