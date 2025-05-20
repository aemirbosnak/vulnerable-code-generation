//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct Graph {
    int vertices;
    int **adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Undirected graph
    graph->adjMatrix[dest][src] = 1;
}

bool isSafe(int vertex, int color[], int c, Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph* graph, int m, int color[], int vertex) {
    if (vertex == graph->vertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, c, graph)) {
            color[vertex] = c; // Assign color c
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }
            color[vertex] = 0; // Backtrack if no solution found
        }
    }
    return false;
}

void graphColoring(Graph* graph, int m) {
    int* color = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = 0; // Initialize all vertices with no color
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Coloring of graph is possible with %d colors:\n", m);
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Coloring of graph is not possible with %d colors.\n", m);
    }

    free(color);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices, edges, src, dest, m;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest format):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);
    freeGraph(graph);

    return 0;
}