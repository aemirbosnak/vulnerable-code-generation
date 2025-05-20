//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    int *neighbors;
} Node;

typedef struct graph {
    int n;
    Node *nodes;
} Graph;

Graph *create_graph() {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = 0;
    g->nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    return g;
}

void add_node(Graph *g) {
    if (g->n >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    Node *node = &g->nodes[g->n];
    node->id = g->n;
    node->degree = 0;
    node->neighbors = (int *)malloc(MAX_EDGES * sizeof(int));
    g->n++;
}

void add_edge(Graph *g, int u, int v) {
    Node *node1 = &g->nodes[u];
    Node *node2 = &g->nodes[v];
    node1->degree++;
    node2->degree++;
    node1->neighbors[node1->degree - 1] = v;
    node2->neighbors[node2->degree - 1] = u;
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        Node *node = &g->nodes[i];
        printf("Node %d: ", node->id);
        for (int j = 0; j < node->degree; j++) {
            printf("%d ", node->neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Graph *g = create_graph();
    int n = 10;
    for (int i = 0; i < n; i++) {
        add_node(g);
    }
    for (int i = 0; i < n; i++) {
        int u = rand() % n;
        int v = rand() % n;
        while (u == v) {
            v = rand() % n;
        }
        add_edge(g, u, v);
    }
    printf("Graph:\n");
    print_graph(g);
    return 0;
}