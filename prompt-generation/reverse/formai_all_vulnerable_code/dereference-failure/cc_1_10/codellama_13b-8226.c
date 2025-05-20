//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: multivariable
// Graph representation example program in a multivariable style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node
struct Node {
    int id;
    char name[50];
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int num_vertices;
    struct Node** adjacency_list;
};

// Function to create a new graph
struct Graph* create_graph(int num_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adjacency_list = (struct Node**)malloc(num_vertices * sizeof(struct Node*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }
    return graph;
}

// Function to add a new node to the graph
void add_node(struct Graph* graph, int id, char* name) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    graph->adjacency_list[id] = new_node;
}

// Function to add an edge between two nodes
void add_edge(struct Graph* graph, int source, int destination) {
    struct Node* source_node = graph->adjacency_list[source];
    struct Node* destination_node = graph->adjacency_list[destination];
    if (source_node == NULL || destination_node == NULL) {
        return;
    }
    source_node->next = destination_node;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Node* node = graph->adjacency_list[i];
        if (node != NULL) {
            printf("%d -> %s\n", node->id, node->name);
        }
    }
}

// Function to free the graph
void free_graph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Node* node = graph->adjacency_list[i];
        while (node != NULL) {
            struct Node* next = node->next;
            free(node);
            node = next;
        }
    }
    free(graph->adjacency_list);
    free(graph);
}

int main() {
    struct Graph* graph = create_graph(5);
    add_node(graph, 0, "A");
    add_node(graph, 1, "B");
    add_node(graph, 2, "C");
    add_node(graph, 3, "D");
    add_node(graph, 4, "E");
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    free_graph(graph);
    return 0;
}