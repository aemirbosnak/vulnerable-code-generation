//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0; // Initialize the adjacency matrix to 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // Undirected graph
}

// Function to check if it's safe to color a vertex with a given color
bool isSafe(Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the coloring problem
bool graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color c
            
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }

            color[vertex] = 0; // Backtrack
        }
    }
    return false; // No valid coloring found
}

// Function to solve the graph coloring problem
bool graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize colors to 0
    }
    bool result = graphColoringUtil(graph, m, color, 0);
    
    if (result) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist\n");
    }
    
    free(color);
    return result;
}

// Main function to demonstrate graph coloring
int main() {
    int vertices, edges, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    // Free the graph memory
    free(graph);
    return 0;
}