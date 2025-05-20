//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: excited
/*
 * Graph Representation Example Program
 *
 * Author: [Your Name]
 * Date: [Current Date]
 *
 * Description: This program creates a graph with 5 vertices and 5 edges.
 * It demonstrates the use of adjacency lists to represent the graph.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the graph structure
struct Graph {
    int numVertices;
    int numEdges;
    int* adjacencyList;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->adjacencyList = (int*)malloc(sizeof(int) * numVertices * numEdges);
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    graph->adjacencyList[startVertex * graph->numVertices + endVertex] = 1;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyList[i * graph->numVertices + j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a graph with 5 vertices and 5 edges
    struct Graph* graph = createGraph(5, 5);

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