//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EDGES 100
#define MAX_NODES 100

typedef struct {
    int node;
    int weight;
    struct Node *next;
} Edge;

typedef struct {
    int node;
    struct Node *next;
} Node;

Node *create_node(int node) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

Edge *create_edge(int node, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->node = node;
    new_edge->weight = weight;
    new_edge->next = NULL;
    return new_edge;
}

void add_edge(Node *node, Edge *edge) {
    Edge *new_edge = create_edge(edge->node, edge->weight);
    new_edge->next = node->next;
    node->next = new_edge;
}

void print_graph(Node *node) {
    while (node!= NULL) {
        printf("%d -> ", node->node);
        Edge *edge = node->next;
        while (edge!= NULL) {
            printf("%d (%d)", edge->node, edge->weight);
            if (edge->next!= NULL) {
                printf(", ");
            }
            edge = edge->next;
        }
        printf("\n");
        node = node->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node *graph[MAX_NODES];
    for (int i = 0; i < n; i++) {
        graph[i] = create_node(i);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(graph[u], create_edge(v, w));
    }

    print_graph(graph[0]);

    return 0;
}