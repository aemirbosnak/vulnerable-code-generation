//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: decentralized
// Decentralized Graph Representation in C

#include <stdio.h>
#include <stdlib.h>

// Define a struct for a graph node
typedef struct {
    int id;
    int *neighbors;
    int num_neighbors;
} Node;

// Define a struct for a graph
typedef struct {
    Node **nodes;
    int num_nodes;
} Graph;

// Function to create a new graph
Graph *create_graph(int num_nodes) {
    Graph *graph = malloc(sizeof(Graph));
    graph->nodes = malloc(num_nodes * sizeof(Node *));
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = malloc(sizeof(Node));
        graph->nodes[i]->id = i;
        graph->nodes[i]->neighbors = NULL;
        graph->nodes[i]->num_neighbors = 0;
    }
    return graph;
}

// Function to add a node to a graph
void add_node(Graph *graph, int node_id) {
    if (graph->num_nodes >= graph->nodes) {
        return;
    }
    graph->nodes[graph->num_nodes++] = malloc(sizeof(Node));
    graph->nodes[graph->num_nodes - 1]->id = node_id;
    graph->nodes[graph->num_nodes - 1]->neighbors = NULL;
    graph->nodes[graph->num_nodes - 1]->num_neighbors = 0;
}

// Function to add an edge between two nodes
void add_edge(Graph *graph, int node1, int node2) {
    if (node1 < 0 || node1 >= graph->num_nodes || node2 < 0 || node2 >= graph->num_nodes) {
        return;
    }
    Node *node1_ptr = graph->nodes[node1];
    Node *node2_ptr = graph->nodes[node2];
    node1_ptr->neighbors = realloc(node1_ptr->neighbors, (node1_ptr->num_neighbors + 1) * sizeof(int));
    node1_ptr->neighbors[node1_ptr->num_neighbors++] = node2;
    node2_ptr->neighbors = realloc(node2_ptr->neighbors, (node2_ptr->num_neighbors + 1) * sizeof(int));
    node2_ptr->neighbors[node2_ptr->num_neighbors++] = node1;
}

// Function to print a graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        Node *node = graph->nodes[i];
        printf("Node %d:", node->id);
        for (int j = 0; j < node->num_neighbors; j++) {
            printf(" %d", node->neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    Graph *graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);
    print_graph(graph);
    return 0;
}