//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50 // Maximum number of vertices in the graph

typedef struct {
    int vertices; // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

void initializeGraph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize adjacency matrix
        }
    }
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Add edge from dest to src (undirected graph)
}

int isSafe(int vertex, int color[], Graph *graph, int c) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe if adjacent vertex has the same color
        }
    }
    return 1; // Safe
}

int graphColoringUtil(Graph *graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return 1; // All vertices colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, graph, c)) {
            color[vertex] = c; // Assign color to vertex

            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1; // Proceed to assign color to the next vertex
            }

            color[vertex] = 0; // Backtrack if no valid color found
        }
    }
    return 0; // If no color can be assigned
}

void graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize colors
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists for the given graph with %d colors.\n", m);
    }

    free(color); // Free allocated memory
}

int main() {
    Graph graph;
    int vertices, edges, src, dest, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(&graph, m);

    return 0;
}