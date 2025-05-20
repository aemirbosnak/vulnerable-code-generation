//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct edge {
    int weight;
    struct node* to;
} Edge;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Edge* create_edge(int weight, Node* to) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->weight = weight;
    new_edge->to = to;
    return new_edge;
}

void add_edge(Node* from, Edge* edge) {
    from->next = (Node*)edge;
}

int main() {
    Node* nodes[MAX_NODES];
    Edge* edges[MAX_EDGES];
    int num_nodes, num_edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the nodes and their data:\n");
    for (int i = 0; i < num_nodes; i++) {
        int data;
        scanf("%d", &data);
        nodes[i] = create_node(data);
    }

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < num_edges; i++) {
        int from_node_index, to_node_index, weight;
        scanf("%d %d %d", &from_node_index, &to_node_index, &weight);
        Node* from_node = nodes[from_node_index];
        Node* to_node = nodes[to_node_index];
        Edge* edge = create_edge(weight, to_node);
        add_edge(from_node, edge);
    }

    return 0;
}