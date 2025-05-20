//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge* edge; // Pointer to array of edges
};

// Structure to represent an edge
struct Edge {
    int src; // Source vertex
    int dest; // Destination vertex
};

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->E++;
    graph->edge = realloc(graph->edge, graph->E * sizeof(struct Edge));
    graph->edge[graph->E - 1].src = src;
    graph->edge[graph->E - 1].dest = dest;
}

// Function to print a graph
void printGraph(struct Graph* graph) {
    printf("Vertices: %d\n", graph->V);
    printf("Edges: %d\n", graph->E);
    for (int i = 0; i < graph->E; i++) {
        printf("Edge %d: (%d, %d)\n", i, graph->edge[i].src, graph->edge[i].dest);
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = 5;
    graph->E = 0;
    graph->edge = NULL;

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}