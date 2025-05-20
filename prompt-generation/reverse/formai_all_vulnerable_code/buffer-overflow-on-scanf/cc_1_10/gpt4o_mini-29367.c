//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50  // Maximum number of vertices in the graph

typedef struct {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to allocate a new graph with numVertices vertices
Graph* createGraph(int numVertices) {
    int i, j;
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->numVertices = numVertices;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            newGraph->adjacencyMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Directed graph (src -> dest)
    graph->adjacencyMatrix[dest][src] = 1; // Assuming undirected graph
}

// Utility function to check if it is safe to color a vertex
int isSafe(Graph* graph, int vertexColors[], int vertex, int color) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && vertexColors[i] == color) {
            return 0; // Not safe if adjacent vertex has the same color
        }
    }
    return 1; // Safe to color
}

// Recursive function to solve m-coloring problem
int graphColoringUtil(Graph* graph, int m, int vertexColors[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices colored successfully
    }

    for (int color = 1; color <= m; color++) {
        if (isSafe(graph, vertexColors, vertex, color)) {
            vertexColors[vertex] = color; // Assign color

            if (graphColoringUtil(graph, m, vertexColors, vertex + 1)) {
                return 1; // Proceed if successful
            }

            vertexColors[vertex] = 0; // Backtrack
        }
    }
    return 0; // No color could be assigned
}

// Function to solve m-coloring problem
int graphColoring(Graph* graph, int m) {
    int* vertexColors = (int*)malloc(graph->numVertices * sizeof(int));
    
    // Initialize all vertices as uncolored
    for (int i = 0; i < graph->numVertices; i++) {
        vertexColors[i] = 0;
    }

    if (graphColoringUtil(graph, m, vertexColors, 0) == 0) {
        printf("Solution does not exist.\n");
        free(vertexColors);
        return 0;
    }

    // Print the solution
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, vertexColors[i]);
    }

    free(vertexColors);
    return 1;
}

int main() {
    int numVertices, edges, src, dest, m;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    free(graph);
    return 0;
}