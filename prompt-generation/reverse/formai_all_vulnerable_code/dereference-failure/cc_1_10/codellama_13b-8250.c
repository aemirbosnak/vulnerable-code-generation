//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: systematic
/*
 * A systematic C Graph representation example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the graph
struct Node {
    char* name;
    int id;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    struct Node* nodes;
    int num_nodes;
    int num_edges;
};

// Function to create a new node with the given name and id
struct Node* create_node(char* name, int id) {
    struct Node* node = malloc(sizeof(struct Node));
    node->name = strdup(name);
    node->id = id;
    node->next = NULL;
    return node;
}

// Function to add a node to the graph
void add_node(struct Graph* graph, struct Node* node) {
    node->next = graph->nodes;
    graph->nodes = node;
    graph->num_nodes++;
}

// Function to add an edge between two nodes
void add_edge(struct Graph* graph, struct Node* node1, struct Node* node2) {
    node1->next = node2;
    graph->num_edges++;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    struct Node* node = graph->nodes;
    while (node != NULL) {
        printf("%s\n", node->name);
        node = node->next;
    }
}

int main() {
    // Create a new graph
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->nodes = NULL;
    graph->num_nodes = 0;
    graph->num_edges = 0;

    // Create nodes
    struct Node* node1 = create_node("A", 1);
    struct Node* node2 = create_node("B", 2);
    struct Node* node3 = create_node("C", 3);

    // Add nodes to the graph
    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);

    // Add edges between nodes
    add_edge(graph, node1, node2);
    add_edge(graph, node2, node3);
    add_edge(graph, node3, node1);

    // Print the graph
    print_graph(graph);

    return 0;
}