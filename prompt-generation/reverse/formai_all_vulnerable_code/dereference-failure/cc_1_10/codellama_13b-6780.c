//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: authentic
// C program to demonstrate a unique graph representation using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

// Function to create a new graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjacencyMatrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->adjacencyMatrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adjacencyMatrix[u][v] = 1;
    graph->adjacencyMatrix[v][u] = 1;
}

// Function to print a graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    printGraph(graph);
    return 0;
}