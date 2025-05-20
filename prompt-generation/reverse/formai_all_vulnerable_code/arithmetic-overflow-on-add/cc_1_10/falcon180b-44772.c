//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    struct node **neighbors;
} Node;

Node *create_node(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->neighbors = (Node **)malloc(MAX_NODES * sizeof(Node *));
    memset(node->neighbors, 0, MAX_NODES * sizeof(Node *));
    return node;
}

void add_edge(Node *node1, Node *node2) {
    node1->neighbors[node1->degree++] = node2;
    node2->neighbors[node2->degree++] = node1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node **nodes = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++) {
        nodes[i] = create_node(i);
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(nodes[u], nodes[v]);
    }

    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < nodes[i]->degree; j++) {
            printf("%d ", nodes[i]->neighbors[j]->id);
        }
        printf("\n");
    }

    return 0;
}