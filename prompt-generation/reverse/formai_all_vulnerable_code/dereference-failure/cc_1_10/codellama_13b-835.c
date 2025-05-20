//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: unmistakable
// Unmistakable C Graph Representation Example Program

#include <stdio.h>
#include <stdlib.h>

// Graph Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Graph Structure
struct Graph {
    int num_nodes;
    struct Node** nodes;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new graph
struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(num_nodes * sizeof(struct Node*));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

// Function to add an edge between two nodes
void add_edge(struct Graph* graph, int src, int dest) {
    struct Node* src_node = graph->nodes[src];
    struct Node* dest_node = graph->nodes[dest];
    if (src_node == NULL) {
        src_node = create_node(src);
        graph->nodes[src] = src_node;
    }
    if (dest_node == NULL) {
        dest_node = create_node(dest);
        graph->nodes[dest] = dest_node;
    }
    src_node->next = dest_node;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct Node* node = graph->nodes[i];
        if (node == NULL) {
            continue;
        }
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    struct Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}