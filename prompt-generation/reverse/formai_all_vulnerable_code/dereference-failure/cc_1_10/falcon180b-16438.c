//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the graph structure
typedef struct graph {
    int num_nodes;
    Node** nodes;
} Graph;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
Graph* create_graph(int num_nodes) {
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));
    if (new_graph == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_graph->num_nodes = num_nodes;
    new_graph->nodes = (Node**)malloc(sizeof(Node*) * num_nodes);
    if (new_graph->nodes == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < num_nodes; i++) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}

// Function to add an edge between two nodes
void add_edge(Graph* graph, int node1, int node2) {
    Node* new_node = create_node(node2);
    new_node->next = graph->nodes[node1];
    graph->nodes[node1] = new_node;
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: ", i);
        Node* current_node = graph->nodes[i];
        while (current_node!= NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    print_graph(graph);
    return 0;
}