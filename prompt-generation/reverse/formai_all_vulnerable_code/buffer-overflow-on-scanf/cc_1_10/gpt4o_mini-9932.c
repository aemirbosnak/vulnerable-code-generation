//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

// Function to create a graph with numVertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**) malloc(numVertices * sizeof(int*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*) malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize adjacency matrix to 0
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1;
    graph->adjMatrix[endVertex][startVertex] = 1; // Undirected graph
}

// Function to determine if a color can be assigned to a vertex
int isSafe(Graph* graph, int vertex, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && color[i] == c) {
            return 0; // Not safe to color
        }
    }
    return 1; // Safe to color
}

// Function to solve the m-coloring problem using backtracking
int graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->numVertices) {
        return 1; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, vertex, color, c)) {
            color[vertex] = c; // Assign color

            // Recursively call to color the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return 1;
            }

            color[vertex] = 0; // Reset color (backtracking)
        }
    }
    return 0; // No solution found
}

// Function to solve the m-coloring problem
int graphColoring(Graph* graph, int m) {
    int* color = (int*) malloc(graph->numVertices * sizeof(int));
    
    // Initialize all vertices to no color (0)
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists! Colors assigned are:\n");
        for (int i = 0; i < graph->numVertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
        free(color);
        return 1;
    } else {
        printf("No solution exists for the given number of colors.\n");
        free(color);
        return 0;
    }
}

// Function to free the graph's memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int numVertices, numEdges, m;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    
    Graph* graph = createGraph(numVertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter the edges (start_vertex end_vertex): \n");
    for (int i = 0; i < numEdges; i++) {
        int startVertex, endVertex;
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(graph, startVertex, endVertex);
    }
    
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    graphColoring(graph, m);
    
    freeGraph(graph);
    return 0;
}