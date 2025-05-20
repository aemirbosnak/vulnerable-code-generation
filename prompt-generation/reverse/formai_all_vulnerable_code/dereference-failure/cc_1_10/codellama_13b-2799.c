//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: synchronous
// Graph representation example program in a synchronous style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the graph
struct Node {
    int id;
    int num_neighbors;
    int* neighbors;
};

// Define a structure to represent the graph
struct Graph {
    int num_nodes;
    struct Node** nodes;
};

// Function to create a new node
struct Node* create_node(int id, int num_neighbors) {
    struct Node* node = malloc(sizeof(struct Node));
    node->id = id;
    node->num_neighbors = num_neighbors;
    node->neighbors = malloc(sizeof(int) * num_neighbors);
    return node;
}

// Function to add a neighbor to a node
void add_neighbor(struct Node* node, int neighbor) {
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

// Function to create a new graph
struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(sizeof(struct Node*) * num_nodes);
    return graph;
}

// Function to add a node to the graph
void add_node(struct Graph* graph, struct Node* node) {
    graph->nodes[graph->num_nodes] = node;
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: ", graph->nodes[i]->id);
        for (int j = 0; j < graph->nodes[i]->num_neighbors; j++) {
            printf("%d ", graph->nodes[i]->neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 nodes
    struct Graph* graph = create_graph(5);

    // Create nodes for the graph
    struct Node* node1 = create_node(1, 2);
    struct Node* node2 = create_node(2, 3);
    struct Node* node3 = create_node(3, 2);
    struct Node* node4 = create_node(4, 2);
    struct Node* node5 = create_node(5, 1);

    // Add nodes to the graph
    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);
    add_node(graph, node5);

    // Add neighbors to the nodes
    add_neighbor(node1, 2);
    add_neighbor(node1, 4);
    add_neighbor(node2, 3);
    add_neighbor(node2, 5);
    add_neighbor(node3, 1);
    add_neighbor(node3, 4);
    add_neighbor(node4, 2);
    add_neighbor(node4, 3);
    add_neighbor(node5, 1);

    // Print the graph
    print_graph(graph);

    return 0;
}