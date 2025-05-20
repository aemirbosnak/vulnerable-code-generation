//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    int num_nodes;
    Node *nodes;
} Graph;

Graph *create_graph(int num_nodes) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (Node *)malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].data = i;
        graph->nodes[i].next = NULL;
    }
    return graph;
}

void add_edge(Graph *graph, int node1, int node2) {
    Node *node1_ptr = &(graph->nodes[node1]);
    Node *node2_ptr = &(graph->nodes[node2]);
    node1_ptr->next = node2_ptr;
    node2_ptr->next = node1_ptr;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *node_ptr = &(graph->nodes[i]);
        printf("%d: ", node_ptr->data);
        while (node_ptr->next!= NULL) {
            printf("%d ", node_ptr->next->data);
            node_ptr = node_ptr->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}