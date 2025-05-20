//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: imaginative
// Unique C Graph Representation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    bool** edges;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = malloc(numVertices * sizeof(bool*));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = malloc(numVertices * sizeof(bool));
        for (int j = 0; j < numVertices; j++) {
            graph->edges[i][j] = false;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int from, int to) {
    graph->edges[from][to] = true;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a new graph with 5 vertices and 4 edges
    struct Graph* graph = createGraph(5, 4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}