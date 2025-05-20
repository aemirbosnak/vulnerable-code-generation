//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
// Graph representation example program in C

#include <stdio.h>
#include <stdlib.h>

// Struct to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int **edges; // Adjacency matrix
};

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0;
    graph->edges = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->edges[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->edges[src][dest] = 1;
    graph->edges[dest][src] = 1;
    graph->E++;
}

// Function to print a graph
void printGraph(struct Graph* graph) {
    printf("Graph with %d vertices and %d edges\n", graph->V, graph->E);
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    printGraph(graph);
    return 0;
}