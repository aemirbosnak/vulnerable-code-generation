//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
struct Node {
    int value;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    struct Node* nodes[MAX_NODES];
    int num_nodes;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to add a node to a graph
void addNode(struct Graph* graph, struct Node* node) {
    graph->nodes[graph->num_nodes++] = node;
}

// Function to create a new graph
struct Graph* createGraph() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_nodes = 0;
    return graph;
}

// Function to print the nodes in a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d -> ", graph->nodes[i]->value);
    }
    printf("\n");
}

int main() {
    // Create a graph with 5 nodes
    struct Graph* graph = createGraph();
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);

    // Add nodes to the graph
    addNode(graph, node1);
    addNode(graph, node2);
    addNode(graph, node3);
    addNode(graph, node4);
    addNode(graph, node5);

    // Print the nodes in the graph
    printGraph(graph);

    return 0;
}