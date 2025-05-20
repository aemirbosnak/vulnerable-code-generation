//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

// Function to check if the current color assignment is safe for vertex v
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return FALSE;
        }
    }
    return TRUE;
}

// Recursive utility function to solve m-coloring problem
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int numVertices) {
    // Base case: If all vertices are assigned a color then return true
    if (v == numVertices) {
        return TRUE;
    }
    
    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c, numVertices)) {
            color[v] = c; // Assigning color c to vertex v
            
            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, numVertices)) {
                return TRUE;
            }
            
            // Backtrack if color c doesn't lead to a solution
            color[v] = 0;
        }
    }
    
    return FALSE; // No solution found
}

// Function to solve the m-coloring problem using backtracking
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices) {
    int *color = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        color[i] = 0; // Initialize all colors as 0 (no color)
    }
    
    if (graphColoringUtil(graph, m, color, 0, numVertices)) {
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }
    
    free(color);
}

// Function to read the graph from user input
void readGraph(int graph[MAX_VERTICES][MAX_VERTICES], int *numVertices) {
    printf("Enter the number of vertices: ");
    scanf("%d", numVertices);
    
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Main function to execute the program
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int m, numVertices;

    readGraph(graph, &numVertices);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, numVertices);
    
    return 0;
}