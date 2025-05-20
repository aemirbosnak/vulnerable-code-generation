//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int **adjMatrix; // Adjacency matrix representation
    int numVertices; // Number of vertices
} Graph;

Graph* createGraph(int vertices);
void freeGraph(Graph *graph);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
int graphColoring(Graph *graph, int m);
int isSafe(int v, Graph *graph, int color[], int c);
void printSolution(int color[], int n);

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    if(vertices > MAX_VERTICES) {
        printf("Number of vertices should be less than or equal to %d\n", MAX_VERTICES);
        return 1;
    }

    Graph *graph = createGraph(vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (src dest) format:\n");
    for(int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);
    
    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (graphColoring(graph, m)) {
        printf("Solution exists with %d colors.\n", m);
    } else {
        printf("No solution with %d colors.\n", m);
    }

    freeGraph(graph);
    return 0;
}

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }
    
    return graph;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Undirected graph
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(Graph *graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int graphColoringUtil(Graph *graph, int m, int color[], int v) {
    if (v == graph->numVertices) {
        printSolution(color, graph->numVertices);
        return TRUE;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return TRUE;
            }
            color[v] = 0; // Backtrack
        }
    }

    return FALSE;
}

int graphColoring(Graph *graph, int m) {
    int *color = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = 0; // Initialize colors
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution doesn't exist\n");
        return FALSE;
    }

    free(color);
    return TRUE;
}

int isSafe(int v, Graph *graph, int color[], int c) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] && color[i] == c) {
            return FALSE;
        }
    }
    return TRUE;
}

void printSolution(int color[], int n) {
    printf("Assigned colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}