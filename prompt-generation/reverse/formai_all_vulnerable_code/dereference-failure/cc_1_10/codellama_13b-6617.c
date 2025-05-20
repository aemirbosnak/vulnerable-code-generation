//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: portable
// Portable graph representation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Graph structure
typedef struct {
    int nVertices;
    int nEdges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Create a new graph
Graph* createGraph(int nVertices, int nEdges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->nVertices = nVertices;
    graph->nEdges = nEdges;
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int vertex1, int vertex2) {
    graph->adjMatrix[vertex1][vertex2] = 1;
    graph->adjMatrix[vertex2][vertex1] = 1;
}

// Check if two vertices are adjacent
int areAdjacent(Graph* graph, int vertex1, int vertex2) {
    return graph->adjMatrix[vertex1][vertex2] == 1;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->nVertices; i++) {
        for (int j = 0; j < graph->nVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Test the graph
int main() {
    Graph* graph = createGraph(5, 6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}