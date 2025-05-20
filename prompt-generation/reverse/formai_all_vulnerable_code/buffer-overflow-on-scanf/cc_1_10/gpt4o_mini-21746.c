//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int **adjacencyMatrix;
    int numVertices;
} Graph;

// Function to create a new graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyMatrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // Undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Utility function to check if the current color assignment is safe for vertex v
int isSafe(int vertex, Graph *graph, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Function to solve the m-coloring problem using backtracking
int graphColoringUtil(Graph *graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c; // Assign color c
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return 0; // If no color can be assigned
}

// Function to solve the m-coloring problem
void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize all vertices to uncolored
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Assigned colors are:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d ----> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for the given coloring.\n");
    }

    free(color);
}

// Function to free the memory allocated for graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    int numVertices, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    Graph *graph = createGraph(numVertices);

    printf("Enter the edges (source target) (-1 -1 to stop):\n");
    int src, dest;
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) {
            break;
        }
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printGraph(graph);
    graphColoring(graph, m);
    freeGraph(graph);

    return 0;
}