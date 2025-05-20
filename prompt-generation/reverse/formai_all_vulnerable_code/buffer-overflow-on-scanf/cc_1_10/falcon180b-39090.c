//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Edge {
    int from, to, weight;
};

struct Node {
    int id;
    int degree;
    struct Edge *edges;
};

void init_node(struct Node *node, int id) {
    node->id = id;
    node->degree = 0;
    node->edges = NULL;
}

void add_edge(struct Node *src, struct Node *dest, int weight) {
    struct Edge *edge = malloc(sizeof(struct Edge));
    edge->from = src->id;
    edge->to = dest->id;
    edge->weight = weight;
    src->degree++;
    dest->degree++;
    src->edges = realloc(src->edges, sizeof(struct Edge) * src->degree);
    dest->edges = realloc(dest->edges, sizeof(struct Edge) * dest->degree);
    src->edges[src->degree - 1] = *edge;
    dest->edges[dest->degree - 1] = *edge;
}

int main() {
    int n, m, from, to, weight;
    scanf("%d %d", &n, &m);

    struct Node nodes[n];
    for (int i = 0; i < n; i++) {
        init_node(&nodes[i], i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        add_edge(&nodes[from], &nodes[to], weight);
    }

    for (int i = 0; i < n; i++) {
        printf("Node %d:\n", i);
        printf("Edges:\n");
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("%d -> %d (%d)\n", i, nodes[i].edges[j].to, nodes[i].edges[j].weight);
        }
    }

    return 0;
}