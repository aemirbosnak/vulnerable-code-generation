//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: calm
/*
 * A unique C Data structures visualization example program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>

// A structure to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// A structure to represent a graph
struct Graph {
    int num_vertices;
    struct Node** adjacency_list;
};

// A function to create a new graph
struct Graph* create_graph(int num_vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_list = malloc(sizeof(struct Node*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }
    return graph;
}

// A function to add a new edge to a graph
void add_edge(struct Graph* graph, int src, int dest) {
    // Add the destination to the adjacency list of the source
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = dest;
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;
}

// A function to print the graph
void print_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        struct Node* node = graph->adjacency_list[i];
        while (node != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0;
}