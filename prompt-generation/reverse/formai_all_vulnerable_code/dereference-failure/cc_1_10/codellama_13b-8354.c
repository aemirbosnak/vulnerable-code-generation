//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
/*
 * C Graph Representation Example Program
 *
 * This program demonstrates a simple graph representation in C.
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for representing a graph node
struct node {
    int value;
    struct node *next;
};

// Structure for representing a graph
struct graph {
    struct node *head;
};

// Function to create a new graph node
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the graph
void add_node(struct graph *graph, int value) {
    struct node *new_node = create_node(value);
    new_node->next = graph->head;
    graph->head = new_node;
}

// Function to print the graph
void print_graph(struct graph *graph) {
    struct node *current = graph->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->head = NULL;

    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);

    print_graph(graph);

    return 0;
}