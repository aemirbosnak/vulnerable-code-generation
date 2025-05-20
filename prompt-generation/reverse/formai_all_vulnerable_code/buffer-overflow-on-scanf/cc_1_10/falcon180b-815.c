//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    struct node *neighbors[MAX_EDGES];
} Node;

typedef struct graph {
    int n;
    Node *nodes[MAX_NODES];
} Graph;

Graph *create_graph(int n) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->n = n;
    for (int i = 0; i < n; i++) {
        g->nodes[i] = (Node *) malloc(sizeof(Node));
        g->nodes[i]->id = i;
        g->nodes[i]->degree = 0;
        for (int j = 0; j < MAX_EDGES; j++) {
            g->nodes[i]->neighbors[j] = NULL;
        }
    }
    return g;
}

void add_edge(Graph *g, int u, int v) {
    Node *n1 = g->nodes[u];
    Node *n2 = g->nodes[v];
    n1->degree++;
    n2->degree++;
    n1->neighbors[n1->degree - 1] = n2;
    n2->neighbors[n2->degree - 1] = n1;
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("Node %d: ", g->nodes[i]->id);
        for (int j = 0; j < g->nodes[i]->degree; j++) {
            printf("(%d) ", g->nodes[i]->neighbors[j]->id);
        }
        printf("\n");
    }
}

void free_graph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->nodes[i]);
    }
    free(g);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = create_graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(g, u, v);
    }
    print_graph(g);
    free_graph(g);
    return 0;
}