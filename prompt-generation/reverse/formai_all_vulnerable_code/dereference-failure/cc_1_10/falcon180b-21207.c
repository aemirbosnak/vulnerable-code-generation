//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int data;
    int visited;
    struct node *next;
} Node;

typedef struct edge {
    int from;
    int to;
    int weight;
    struct edge *next;
} Edge;

typedef struct graph {
    Node *nodes[MAX_NODES];
    Edge *edges[MAX_EDGES];
    int n_nodes;
    int n_edges;
} Graph;

Graph *create_graph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n_nodes = 0;
    g->n_edges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g->nodes[i] = NULL;
    }
    for (int i = 0; i < MAX_EDGES; i++) {
        g->edges[i] = NULL;
    }
    return g;
}

void add_node(Graph *g, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->visited = 0;
    node->next = NULL;
    g->nodes[g->n_nodes++] = node;
}

void add_edge(Graph *g, int from, int to, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;
    g->edges[g->n_edges++] = edge;
}

void dfs(Graph *g, int start) {
    Node *node = g->nodes[start];
    node->visited = 1;
    printf("%d ", node->data);
    for (Edge *e = g->edges[start]; e!= NULL; e = e->next) {
        if (!g->nodes[e->to]->visited) {
            dfs(g, e->to);
        }
    }
}

int main() {
    Graph *g = create_graph();
    for (int i = 0; i < 10; i++) {
        add_node(g, i);
    }
    for (int i = 0; i < 9; i++) {
        add_edge(g, i, i + 1, rand() % 10);
    }
    int start = rand() % 10;
    printf("Depth first search starting from node %d:\n", start);
    dfs(g, start);
    printf("\n");
    return 0;
}