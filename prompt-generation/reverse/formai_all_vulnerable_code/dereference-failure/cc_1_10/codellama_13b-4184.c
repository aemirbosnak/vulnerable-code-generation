//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: inquisitive
/*
 * A unique C Graph representation example program in an inquisitive style
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A structure to represent a graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    int** edges;
} Graph;

// A structure to represent a vertex
typedef struct Vertex {
    int data;
    bool visited;
} Vertex;

// A function to create a new graph with n vertices and 0 edges
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->numEdges = 0;
    graph->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->edges[i] = (int*)malloc(n * sizeof(int));
        memset(graph->edges[i], 0, n * sizeof(int));
    }
    return graph;
}

// A function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
    graph->numEdges++;
}

// A function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

// A function to print the graph in an inquisitive style
void printGraphInquisitive(Graph* graph) {
    printf("The graph has %d vertices and %d edges\n", graph->numVertices, graph->numEdges);
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d is connected to: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Print the graph in an inquisitive style
    printGraphInquisitive(graph);

    return 0;
}