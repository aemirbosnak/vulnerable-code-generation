//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: protected
// C Graph representation example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph node structure
struct node {
    int id;
    char label[20];
    struct node *next;
};

// Graph structure
struct graph {
    struct node *head;
    struct node *tail;
    int num_nodes;
};

// Function to create a new node
struct node *create_node(int id, char *label) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->id = id;
    strcpy(new_node->label, label);
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
struct graph *create_graph() {
    struct graph *new_graph = malloc(sizeof(struct graph));
    new_graph->head = NULL;
    new_graph->tail = NULL;
    new_graph->num_nodes = 0;
    return new_graph;
}

// Function to add a node to the graph
void add_node(struct graph *graph, int id, char *label) {
    struct node *new_node = create_node(id, label);
    if (graph->head == NULL) {
        graph->head = new_node;
        graph->tail = new_node;
    } else {
        graph->tail->next = new_node;
        graph->tail = new_node;
    }
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(struct graph *graph) {
    struct node *current = graph->head;
    while (current != NULL) {
        printf("Node %d: %s\n", current->id, current->label);
        current = current->next;
    }
}

// Example usage
int main() {
    struct graph *graph = create_graph();
    add_node(graph, 1, "Node 1");
    add_node(graph, 2, "Node 2");
    add_node(graph, 3, "Node 3");
    print_graph(graph);
    return 0;
}