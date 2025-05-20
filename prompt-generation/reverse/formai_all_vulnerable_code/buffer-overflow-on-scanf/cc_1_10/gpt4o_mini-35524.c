//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Function prototypes
int isSafe(int vertex, int color[], int c);
int graphColoringUtil(int m, int color[], int vertex);
void printSolution(int color[]);
void createGraph();

int main() {
    int m;

    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("Please enter the number of vertices (up to %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    if (numVertices < 1 || numVertices > MAX_VERTICES) {
        printf("Error: Number of vertices must be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    createGraph();

    printf("Please enter the number of colors you wish to use: ");
    scanf("%d", &m);

    if (m <= 0) {
        printf("Error: Number of colors must be greater than 0.\n");
        return 1;
    }

    int color[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        color[i] = 0; // Initialize all vertices to no color
    }

    if (graphColoringUtil(m, color, 0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printSolution(color);
    }

    return 0;
}

void createGraph() {
    int edges, src, dest;
    printf("Enter the number of edges:\n");
    scanf("%d", &edges);

    // Initialize graph with 0s
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (source destination) one per line:\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            graph[src][dest] = 1; // Undirected graph
            graph[dest][src] = 1;
        } else {
            printf("Error: Vertex number must be between 0 and %d.\n", numVertices - 1);
            i--; // Decrement to re-enter this edge
        }
    }
}

int isSafe(int vertex, int color[], int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return 0; // This color is not safe
        }
    }
    return 1; // This color is safe
}

int graphColoringUtil(int m, int color[], int vertex) {
    if (vertex == numVertices) {
        return 1; // Successfully colored the graph
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, color, c)) {
            color[vertex] = c; // Assign color c

            if (graphColoringUtil(m, color, vertex + 1)) {
                return 1; // Recur for the next vertex
            }

            color[vertex] = 0; // Backtrack if no color works
        }
    }
    return 0; // No color can be assigned
}

void printSolution(int color[]) {
    printf("Solution: \n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}