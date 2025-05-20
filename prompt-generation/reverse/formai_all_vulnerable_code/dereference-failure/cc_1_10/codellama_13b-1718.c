//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    int* adjacencyList;
};

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int from, int to) {
    graph->adjacencyList[from] = to;
    graph->numEdges++;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d -> ", i);
        int neighbor = graph->adjacencyList[i];
        while (neighbor != -1) {
            printf("%d ", neighbor);
            neighbor = graph->adjacencyList[neighbor];
        }
        printf("\n");
    }
}

// Driver program to test the above functions
int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 5;
    graph->numEdges = 0;
    graph->adjacencyList = (int*)malloc(graph->numVertices * sizeof(int));

    // Initialize the adjacency list
    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjacencyList[i] = -1;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}