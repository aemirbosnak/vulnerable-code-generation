//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct node {
    int id;
    int degree;
    struct edge *edges;
} Node;

typedef struct edge {
    int to;
    int weight;
    struct edge *next;
} Edge;

Node *create_node(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->edges = NULL;
    return node;
}

Edge *create_edge(int to, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void add_edge(Node *from, Node *to, int weight) {
    Edge *edge = create_edge(to->id, weight);
    edge->next = from->edges;
    from->edges = edge;
    to->degree++;
}

void print_graph(Node *nodes) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].id!= -1) {
            printf("%d: ", nodes[i].id);
            Edge *edge = nodes[i].edges;
            while (edge!= NULL) {
                printf("%d ", edge->to);
                edge = edge->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int i, j, n, m;
    scanf("%d %d", &n, &m);

    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    memset(nodes, -1, sizeof(Node) * n);

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(nodes + u - 1, nodes + v - 1, w);
    }

    print_graph(nodes);

    return 0;
}