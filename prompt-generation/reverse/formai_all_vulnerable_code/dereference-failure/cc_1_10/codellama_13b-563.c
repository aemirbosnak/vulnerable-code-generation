//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Define the graph structure
struct graph {
    struct node** adj;
    int num_nodes;
};

// Create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new graph
struct graph* create_graph(int num_nodes) {
    struct graph* new_graph = (struct graph*)malloc(sizeof(struct graph));
    new_graph->num_nodes = num_nodes;
    new_graph->adj = (struct node**)malloc(num_nodes * sizeof(struct node*));
    for (int i = 0; i < num_nodes; i++) {
        new_graph->adj[i] = NULL;
    }
    return new_graph;
}

// Add an edge between two nodes
void add_edge(struct graph* graph, int src, int dest) {
    struct node* src_node = create_node(src);
    struct node* dest_node = create_node(dest);
    src_node->next = dest_node;
    graph->adj[src] = src_node;
}

// Print the graph
void print_graph(struct graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct node* node = graph->adj[i];
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Example usage
int main() {
    struct graph* graph = create_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);
    print_graph(graph);
    return 0;
}