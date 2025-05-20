//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define TRUE 1
#define FALSE 0

typedef struct Graph {
    int nodes;
    int** adjacencyMatrix;
} Graph;

typedef struct Result {
    int* colors;
    int maxColor;
} Result;

Graph* createGraph(int nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = nodes;

    // Allocate memory for adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(nodes * sizeof(int*));
    for(int i = 0; i < nodes; i++)
        graph->adjacencyMatrix[i] = (int*)malloc(nodes * sizeof(int));

    // Initialize the adjacency matrix to zero
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            graph->adjacencyMatrix[i][j] = 0;

    return graph;
}

void addEdge(Graph* graph, int start, int end) {
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1;
}

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->nodes; i++) {
        printf("%d: ", i);
        for(int j = 0; j < graph->nodes; j++) {
            if (graph->adjacencyMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int isSafe(Graph* graph, int node, int color, int* colors) {
    for(int i = 0; i < graph->nodes; i++) {
        if (graph->adjacencyMatrix[node][i] == 1 && colors[i] == color) 
            return FALSE;
    }
    return TRUE;
}

int graphColoringUtil(Graph* graph, int m, int* colors, int node) {
    if (node == graph->nodes) {
        return TRUE; // All nodes colored
    }

    for(int color = 1; color <= m; color++) {
        if (isSafe(graph, node, color, colors)) {
            colors[node] = color;
            if (graphColoringUtil(graph, m, colors, node + 1)) {
                return TRUE;
            }
            colors[node] = 0; // Backtrack
        }
    }
    return FALSE;
}

Result graphColoring(Graph* graph, int m) {
    Result result;
    result.colors = (int*)malloc(graph->nodes * sizeof(int));
    for(int i = 0; i < graph->nodes; i++) {
        result.colors[i] = 0; // Initialize colors to zero
    }

    if (!graphColoringUtil(graph, m, result.colors, 0)) {
        printf("Solution doesn't exist\n");
        result.maxColor = 0;
    } else {
        result.maxColor = m;
    }

    return result;
}

void freeGraph(Graph* graph) {
    for(int i = 0; i < graph->nodes; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    int n, edges, m;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (start end): \n");
    for(int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Graph adjacency list:\n");
    printGraph(graph);

    Result result = graphColoring(graph, m);

    if (result.maxColor > 0) {
        printf("Assigned colors:\n");
        for(int i = 0; i < n; i++) {
            printf("Node %d -> Color %d\n", i, result.colors[i]);
        }
    }

    free(result.colors);
    freeGraph(graph);
    return 0;
}