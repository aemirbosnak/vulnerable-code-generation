//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define graph structure
typedef struct graph {
    int num_vertices;
    Node** adjacency_list;
} Graph;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph with given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* new_graph = (Graph*) malloc(sizeof(Graph));
    new_graph->num_vertices = num_vertices;
    new_graph->adjacency_list = (Node**) malloc(num_vertices * sizeof(Node*));
    for (int i = 0; i < num_vertices; i++) {
        new_graph->adjacency_list[i] = NULL;
    }
    return new_graph;
}

// Function to add an edge between two vertices in the graph
void add_edge(Graph* graph, int u, int v) {
    Node* new_node = create_node(v);
    new_node->next = graph->adjacency_list[u];
    graph->adjacency_list[u] = new_node;
}

// Function to print the graph in a surrealist style
void surreal_print_graph(Graph* graph) {
    printf("In the land of dreams, a graph surreal,\n");
    printf("With %d vertices, its beauty ideal.\n", graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        Node* curr_node = graph->adjacency_list[i];
        while (curr_node!= NULL) {
            printf("%d leads to %d, a path unseen,\n", i, curr_node->data);
            curr_node = curr_node->next;
        }
    }
}

// Main function to test the graph creation and printing
int main() {
    srand(time(NULL));
    int num_vertices = rand() % 10 + 1;
    Graph* graph = create_graph(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            add_edge(graph, i, j);
        }
    }
    surreal_print_graph(graph);
    return 0;
}