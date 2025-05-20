//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

typedef struct {
    int id;
    int weight;
    struct node *next;
} Edge;

typedef struct {
    int id;
    Edge *edges;
} Node;

void add_edge(Node *node, int id, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->id = id;
    new_edge->weight = weight;
    new_edge->next = node->edges;
    node->edges = new_edge;
}

void print_graph(Node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", nodes[i].id);
        Edge *edge = nodes[i].edges;
        while (edge!= NULL) {
            printf("%d ", edge->id);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int n = 5;
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].edges = NULL;
    }

    add_edge(&nodes[0], 1, 5);
    add_edge(&nodes[0], 2, 2);
    add_edge(&nodes[1], 2, 3);
    add_edge(&nodes[1], 4, 4);
    add_edge(&nodes[2], 3, 1);
    add_edge(&nodes[2], 4, 2);
    add_edge(&nodes[3], 4, 1);

    print_graph(nodes, n);

    return 0;
}