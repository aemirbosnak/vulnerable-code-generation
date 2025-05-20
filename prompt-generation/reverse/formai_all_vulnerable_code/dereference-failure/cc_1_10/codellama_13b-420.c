//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: irregular
/*
 *  Example program to demonstrate a unique C Graph representation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    int** edges;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = malloc(numEdges * sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j]) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph);
}

int main() {
    // Create a graph with 5 vertices and 6 edges
    struct Graph* graph = createGraph(5, 6);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Print the graph
    printGraph(graph);

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}