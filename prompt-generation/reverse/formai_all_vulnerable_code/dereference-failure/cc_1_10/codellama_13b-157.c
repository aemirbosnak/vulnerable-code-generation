//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Structures for the graph nodes and edges
typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct edge {
    int from;
    int to;
    struct edge* next;
} Edge;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new edge
Edge* create_edge(int from, int to) {
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->next = NULL;
    return new_edge;
}

// Function to add a node to the graph
void add_node(Node** nodes, int value) {
    Node* new_node = create_node(value);
    new_node->next = *nodes;
    *nodes = new_node;
}

// Function to add an edge to the graph
void add_edge(Edge** edges, int from, int to) {
    Edge* new_edge = create_edge(from, to);
    new_edge->next = *edges;
    *edges = new_edge;
}

// Function to print the graph
void print_graph(Node* nodes) {
    while (nodes != NULL) {
        printf("Node: %d\n", nodes->value);
        Edge* edges = nodes->next;
        while (edges != NULL) {
            printf("  Edge: (%d, %d)\n", edges->from, edges->to);
            edges = edges->next;
        }
        nodes = nodes->next;
    }
}

int main() {
    // Create a graph with 4 nodes and 3 edges
    Node* nodes = NULL;
    Edge* edges = NULL;
    add_node(&nodes, 1);
    add_node(&nodes, 2);
    add_node(&nodes, 3);
    add_node(&nodes, 4);
    add_edge(&edges, 1, 2);
    add_edge(&edges, 2, 3);
    add_edge(&edges, 3, 4);

    // Print the graph
    print_graph(nodes);

    return 0;
}