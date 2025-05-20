//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: standalone
/*
 * Graph representation example program
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Struct for a node in the graph
typedef struct node {
    int id; // Unique identifier for the node
    int value; // Value stored at the node
    struct node *next; // Pointer to the next node
} node_t;

// Struct for a graph
typedef struct graph {
    int num_nodes; // Number of nodes in the graph
    int num_edges; // Number of edges in the graph
    node_t *head; // Pointer to the first node in the graph
} graph_t;

// Function to create a new node
node_t *new_node(int id, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->id = id;
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to create a new graph
graph_t *new_graph() {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = 0;
    graph->num_edges = 0;
    graph->head = NULL;
    return graph;
}

// Function to add a node to a graph
void add_node(graph_t *graph, int id, int value) {
    // Create a new node
    node_t *node = new_node(id, value);

    // Add the node to the graph
    if (graph->head == NULL) {
        // If the graph is empty, make the new node the head
        graph->head = node;
    } else {
        // Otherwise, find the last node in the graph and make it point to the new node
        node_t *curr = graph->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    graph->num_nodes++;
}

// Function to add an edge between two nodes
void add_edge(graph_t *graph, int id1, int id2) {
    // Find the nodes with the given IDs
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    node_t *curr = graph->head;
    while (curr != NULL) {
        if (curr->id == id1) {
            node1 = curr;
        } else if (curr->id == id2) {
            node2 = curr;
        }
        curr = curr->next;
    }

    // Add the edge between the nodes
    if (node1 != NULL && node2 != NULL) {
        node1->next = node2;
        graph->num_edges++;
    }
}

// Function to print the graph
void print_graph(graph_t *graph) {
    node_t *curr = graph->head;
    while (curr != NULL) {
        printf("%d: %d\n", curr->id, curr->value);
        curr = curr->next;
    }
}

int main() {
    // Create a new graph
    graph_t *graph = new_graph();

    // Add some nodes to the graph
    add_node(graph, 1, 5);
    add_node(graph, 2, 10);
    add_node(graph, 3, 15);

    // Add some edges to the graph
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 1, 3);

    // Print the graph
    print_graph(graph);

    return 0;
}