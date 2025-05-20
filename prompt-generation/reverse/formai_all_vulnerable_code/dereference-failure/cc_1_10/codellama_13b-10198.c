//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// A struct to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// A struct to represent a graph
struct Graph {
    int num_vertices;
    struct Node** adjacency_list;
};

// Function to add an edge between two nodes
void add_edge(struct Graph* graph, int src, int dest) {
    // Add the destination node to the adjacency list of the source node
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = dest;
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;

    // Add the source node to the adjacency list of the destination node
    new_node = malloc(sizeof(struct Node));
    new_node->data = src;
    new_node->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = new_node;
}

// Function to print the adjacency list of a given node
void print_adjacency_list(struct Graph* graph, int node) {
    struct Node* current = graph->adjacency_list[node];
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_vertices = 4;
    graph->adjacency_list = malloc(graph->num_vertices * sizeof(struct Node*));
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);

    // Print the adjacency list of each node
    for (int i = 0; i < graph->num_vertices; i++) {
        print_adjacency_list(graph, i);
    }

    return 0;
}