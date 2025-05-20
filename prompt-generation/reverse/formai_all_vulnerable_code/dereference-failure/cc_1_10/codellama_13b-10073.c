//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: recursive
/*
 * A recursive graph representation example program
 */

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a graph node
struct node {
    int data;
    struct node* next;
};

// Define a struct to represent a graph
struct graph {
    struct node* head;
    int num_nodes;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the graph
void add_node(struct graph* graph, int data) {
    struct node* new_node = create_node(data);
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        struct node* temp = graph->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    graph->num_nodes++;
}

// Function to print the graph
void print_graph(struct graph* graph) {
    struct node* temp = graph->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a new graph
    struct graph* graph = malloc(sizeof(struct graph));
    graph->head = NULL;
    graph->num_nodes = 0;

    // Add some nodes to the graph
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);

    // Print the graph
    print_graph(graph);

    return 0;
}