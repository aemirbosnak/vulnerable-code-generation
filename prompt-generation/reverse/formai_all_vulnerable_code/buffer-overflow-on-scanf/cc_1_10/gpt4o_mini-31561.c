//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int v, int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int colors[], int v, int numVertices) {
    if (v == numVertices) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, colors, v, c, numVertices)) {
            colors[v] = c;

            if (graphColoringUtil(graph, m, colors, v + 1, numVertices)) {
                return true;
            }

            colors[v] = 0; // Backtrack
        }
    }
    return false;
}

void printSolution(int colors[], int numVertices) {
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, colors[i]);
    }
}

void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices) {
    int colors[MAX_VERTICES] = {0};

    if (!graphColoringUtil(graph, m, colors, 0, numVertices)) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(colors, numVertices);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize graph as 0
    int numVertices, numEdges;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    if (numVertices > MAX_VERTICES) {
        printf("Number of vertices exceeds maximum limit (%d).\n", MAX_VERTICES);
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges in the format (u v) where u and v are vertices (1 to %d):\n", numVertices);
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u > 0 && u <= numVertices && v > 0 && v <= numVertices) {
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1; // Undirected graph
        } else {
            printf("Invalid edge (%d, %d). Vertices must be between 1 and %d.\n", u, v, numVertices);
            return 1;
        }
    }

    int m;
    printf("Enter the number of colors to be used: ");
    scanf("%d", &m);

    graphColoring(graph, m, numVertices);
    
    return 0;
}