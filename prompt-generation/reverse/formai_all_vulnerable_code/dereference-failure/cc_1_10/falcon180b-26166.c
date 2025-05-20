//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    struct node **neighbors;
} Node;

void init_node(Node *node, int id) {
    node->id = id;
    node->degree = 0;
    node->neighbors = calloc(MAX_NODES, sizeof(Node*));
}

void add_edge(Node *node1, Node *node2) {
    node1->degree++;
    node2->degree++;
    node1->neighbors[node1->degree - 1] = node2;
    node2->neighbors[node2->degree - 1] = node1;
}

void print_graph(Node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("%d ", nodes[i].neighbors[j]->id);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Node nodes[MAX_NODES];
    int n = rand() % (MAX_NODES - 1) + 1;
    for (int i = 0; i < n; i++) {
        init_node(&nodes[i], i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rand() % 2 == 0) {
                add_edge(&nodes[i], &nodes[j]);
            }
        }
    }
    printf("Generated graph:\n");
    print_graph(nodes, n);
    return 0;
}