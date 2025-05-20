//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a graph node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the structure of a graph
typedef struct graph {
    int num_nodes;
    Node **nodes;
} Graph;

// Initialize an empty graph with a given number of nodes
Graph *init_graph(int num_nodes) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (Node **)malloc(num_nodes * sizeof(Node *));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

// Add a node to the graph
void add_node(Graph *graph, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    graph->nodes[graph->num_nodes - 1] = node;
}

// Connect two nodes in the graph
void connect_nodes(Graph *graph, int node1, int node2) {
    Node *current = graph->nodes[node1];
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = graph->nodes[node2];
}

// Print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *current = graph->nodes[i];
        printf("Node %d: ", i);
        while (current!= NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Free the memory used by the graph
void free_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *current = graph->nodes[i];
        while (current!= NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    // Initialize a graph with 5 nodes
    Graph *graph = init_graph(5);

    // Add nodes to the graph
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);

    // Connect nodes 1 and 2
    connect_nodes(graph, 1, 2);

    // Connect nodes 3 and 4
    connect_nodes(graph, 3, 4);

    // Connect nodes 4 and 5
    connect_nodes(graph, 4, 5);

    // Print the graph
    print_graph(graph);

    // Free the memory used by the graph
    free_graph(graph);

    return 0;
}