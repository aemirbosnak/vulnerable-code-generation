//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct {
    int vertexCount;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph with given number of vertices
Graph* createGraph(int vertexCount) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;

    // Initialize adjacency matrix
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int startVertex, int endVertex) {
    graph->adjacencyMatrix[startVertex][endVertex] = 1;
    graph->adjacencyMatrix[endVertex][startVertex] = 1; // Undirected graph
}

// Function to print the adjacency matrix
void printGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current color assignment is safe for vertex `v`
bool isSafe(int v, Graph *graph, int *color, int c) {
    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->adjacencyMatrix[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem using backtracking
bool graphColoringUtil(Graph *graph, int m, int *color, int v) {
    if (v == graph->vertexCount) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color `c`
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }
    return false; // No solution found
}

// Function to solve the graph coloring problem 
void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->vertexCount * sizeof(int));
    memset(color, 0, graph->vertexCount * sizeof(int)); // Initialize colors to 0

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution found:\n");
        for (int i = 0; i < graph->vertexCount; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists\n");
    }
    free(color);
}

int main() {
    int vertexCount, edges, maxColors;

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    Graph *graph = createGraph(vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    printGraph(graph);

    printf("Enter the maximum number of colors: ");
    scanf("%d", &maxColors);

    graphColoring(graph, maxColors);

    free(graph);
    return 0;
}