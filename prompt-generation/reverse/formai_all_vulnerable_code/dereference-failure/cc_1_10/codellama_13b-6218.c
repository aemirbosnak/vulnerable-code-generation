//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: shape shifting
// Shape Shifting Graph Representation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Graph structure
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int** adj; // Adjacency matrix
};

// Create a new Graph with V vertices and E edges
struct Graph* newGraph(int V, int E) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = malloc(V * sizeof(int));
    }
    return graph;
}

// Add an edge between two vertices
void addEdge(struct Graph* graph, int v, int w) {
    graph->adj[v][w] = 1;
}

// Print the graph in a shape shifting style
void printGraph(struct Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1) {
                printf("(%.2d, %.2d) ", i, j);
            }
        }
        printf("\n");
    }
}

// Shift the graph to a new shape
void shiftGraph(struct Graph* graph, int v) {
    int tmp = graph->V - v;
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            graph->adj[i][j] = graph->adj[i + tmp][j + tmp];
        }
    }
    graph->V = tmp;
}

int main() {
    // Create a new graph with 5 vertices and 6 edges
    struct Graph* graph = newGraph(5, 6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    printf("\n");

    // Shift the graph to a new shape
    shiftGraph(graph, 2);
    printGraph(graph);

    return 0;
}