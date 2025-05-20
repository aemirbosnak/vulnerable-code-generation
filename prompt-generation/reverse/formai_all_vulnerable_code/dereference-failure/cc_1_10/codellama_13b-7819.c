//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: calm
// Graph representation example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the graph node
typedef struct node {
    int id;
    struct node* next;
} Node;

// Define the struct for the graph
typedef struct graph {
    int num_nodes;
    Node** nodes;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_nodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(num_nodes * sizeof(Node*));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = malloc(sizeof(Node));
        graph->nodes[i]->id = i;
        graph->nodes[i]->next = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int node1, int node2) {
    Node* current = graph->nodes[node1];
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = graph->nodes[node2];
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node* current = graph->nodes[i];
        printf("Node %d: ", current->id);
        while (current->next != NULL) {
            current = current->next;
            printf("%d ", current->id);
        }
        printf("\n");
    }
}

// Function to free the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    // Create a graph with 5 nodes
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    // Free the graph
    free_graph(graph);

    return 0;
}