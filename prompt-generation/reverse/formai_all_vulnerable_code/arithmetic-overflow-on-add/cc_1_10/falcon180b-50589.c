//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

typedef struct {
    int id;
    int weight;
    int next;
} Edge;

typedef struct {
    int id;
    int degree;
    int *adj;
} Node;

void addEdge(Edge *edges, int u, int v, int w) {
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->id = 0;
    e->weight = w;
    e->next = edges[u].next;
    edges[u].next = e;
    e = (Edge *)malloc(sizeof(Edge));
    e->id = 0;
    e->weight = w;
    e->next = edges[v].next;
    edges[v].next = e;
}

void addNode(Node *nodes, int id) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->id = id;
    n->degree = 0;
    n->adj = (int *)malloc(sizeof(int));
    nodes[id] = *n;
}

int main() {
    Edge edges[MAX_EDGES];
    Node nodes[MAX_NODES];
    int n, m, u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        addNode(nodes, i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(edges, u, v, w);
        nodes[u].degree++;
        nodes[v].degree++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d (%d): ", i, nodes[i].degree);
        Edge *e = edges[i].next;
        while (e!= NULL) {
            printf("%d ", e->id);
            e = e->next;
        }
        printf("\n");
    }

    return 0;
}