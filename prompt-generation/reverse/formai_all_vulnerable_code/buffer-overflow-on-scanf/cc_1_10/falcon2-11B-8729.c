//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_EDGES 10

// Define a structure to represent a graph node
typedef struct graph_node {
    int color; // Color of the node
    int neighbors[MAX_EDGES]; // Array of neighboring nodes
} graph_node_t;

// Function to print the graph
void print_graph(graph_node_t *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", graph[i].color);
        for (int j = 0; j < MAX_EDGES; j++) {
            if (graph[i].neighbors[j]!= -1) {
                printf(" %d", graph[i].neighbors[j]);
            }
        }
        printf("\n");
    }
}

// Function to color the graph
void color_graph(graph_node_t *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        graph[i].color = i;
    }
}

// Function to find an uncolored node
int find_uncolored_node(graph_node_t *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].color == -1) {
            return i;
        }
    }
    return -1; // If all nodes are colored
}

// Function to color a node
void color_node(graph_node_t *graph, int num_nodes, int node) {
    int uncolored_neighbor = -1;
    for (int i = 0; i < MAX_EDGES; i++) {
        if (graph[node].neighbors[i]!= -1) {
            if (graph[graph[node].neighbors[i]].color == -1) {
                uncolored_neighbor = graph[node].neighbors[i];
                break;
            }
        }
    }
    if (uncolored_neighbor == -1) {
        return; // No uncolored neighbor found
    }
    graph[uncolored_neighbor].color = graph[node].color;
    color_node(graph, num_nodes, uncolored_neighbor);
}

// Main function
int main() {
    graph_node_t graph[MAX_NODES];
    int num_nodes = 0;

    // Add nodes and edges to the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the color of node %d: ", i);
        scanf("%d", &graph[i].color);
        for (int j = 0; j < MAX_EDGES; j++) {
            printf("Enter the neighboring node of node %d: ", i);
            scanf("%d", &graph[i].neighbors[j]);
        }
    }

    // Color the graph
    color_graph(graph, num_nodes);

    // Find an uncolored node
    int uncolored_node = find_uncolored_node(graph, num_nodes);
    if (uncolored_node!= -1) {
        color_node(graph, num_nodes, uncolored_node);
    }

    // Print the graph
    printf("Graph with %d nodes:\n", num_nodes);
    print_graph(graph, num_nodes);

    return 0;
}