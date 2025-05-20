//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
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

Node *create_node(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->neighbors = NULL;
    return node;
}

void add_edge(Node *node1, Node *node2) {
    node1->degree++;
    node2->degree++;
    int *neighbors = realloc(node1->neighbors, node1->degree * sizeof(int));
    neighbors[node1->degree - 1] = node2->id;
    node1->neighbors = neighbors;
}

int main() {
    srand(time(NULL));
    int num_nodes = rand() % MAX_NODES + 1;
    Node **nodes = (Node **)malloc(num_nodes * sizeof(Node *));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = create_node(i);
    }

    int num_edges = rand() % MAX_EDGES + 1;
    for (int i = 0; i < num_edges; i++) {
        int node1_id = rand() % num_nodes;
        int node2_id = rand() % num_nodes;
        while (node1_id == node2_id) {
            node2_id = rand() % num_nodes;
        }
        Node *node1 = nodes[node1_id];
        Node *node2 = nodes[node2_id];
        add_edge(node1, node2);
    }

    for (int i = 0; i < num_nodes; i++) {
        Node *node = nodes[i];
        printf("Node %d: ", node->id);
        for (int j = 0; j < node->degree; j++) {
            printf("%d ", node->neighbors[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_nodes; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}