//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    struct Edge* edges;
};

// Structure to represent a edge
struct Edge {
    int source;
    int destination;
};

// Function to create a graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->edges = (struct Edge*) malloc(numVertices * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].destination = destination;
    graph->numEdges++;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->edges[j].source == i) {
                printf("%d ", graph->edges[j].destination);
            }
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Print the graph
    printGraph(graph);

    return 0;
}