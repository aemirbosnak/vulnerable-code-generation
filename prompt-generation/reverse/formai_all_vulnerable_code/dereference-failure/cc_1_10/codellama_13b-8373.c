//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: systematic
/*
 * Unique C Graph representation example program
 *
 * This program demonstrates a unique way of representing a graph in C using
 * a linked list of nodes, where each node has a pointer to its neighboring
 * nodes.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct node {
    int data;
    struct node* neighbors;
};

// Function to create a new node with the given data
struct node* create_node(int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->neighbors = NULL;
    return new_node;
}

// Function to add a new neighbor to a node
void add_neighbor(struct node* node, struct node* neighbor) {
    struct node* curr = node->neighbors;
    while (curr != NULL) {
        if (curr->data == neighbor->data) {
            return; // The neighbor already exists, so don't add it again
        }
        curr = curr->neighbors;
    }
    // Add the neighbor to the end of the list
    neighbor->neighbors = node->neighbors;
    node->neighbors = neighbor;
}

// Function to print the graph
void print_graph(struct node* node) {
    struct node* curr = node;
    while (curr != NULL) {
        printf("%d ", curr->data);
        struct node* neighbor = curr->neighbors;
        while (neighbor != NULL) {
            printf("-> %d ", neighbor->data);
            neighbor = neighbor->neighbors;
        }
        printf("\n");
        curr = curr->neighbors;
    }
}

int main() {
    // Create a graph with the following nodes:
    //   1 - 2 - 3 - 4 - 5
    //      \       /
    //       6 - 7
    struct node* node1 = create_node(1);
    struct node* node2 = create_node(2);
    struct node* node3 = create_node(3);
    struct node* node4 = create_node(4);
    struct node* node5 = create_node(5);
    struct node* node6 = create_node(6);
    struct node* node7 = create_node(7);

    add_neighbor(node1, node2);
    add_neighbor(node2, node3);
    add_neighbor(node3, node4);
    add_neighbor(node4, node5);
    add_neighbor(node5, node1);
    add_neighbor(node3, node6);
    add_neighbor(node6, node7);
    add_neighbor(node7, node3);

    print_graph(node1);

    return 0;
}