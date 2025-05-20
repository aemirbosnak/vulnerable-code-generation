//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
/* This program solves the graph coloring problem using backtracking algorithm 
   inspired by Claude Shannon's theory of communication. In this problem, we 
   have to assign a color to each vertex of a given graph such that no adjacent 
   vertices have the same color. */

#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

/* Function to check if it is safe to color the vertex with the specified color */
bool isSafe(int vertex, int color, int graph[MAX_VERTICES][MAX_VERTICES], int colorAssignment[]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && colorAssignment[i] == color) {
            return false;
        }
    }
    return true;
}

/* Function to recursively assign colors to vertices */
bool colorVertices(int graph[MAX_VERTICES][MAX_VERTICES], int colorAssignment[], int numVertices, int numColors, int currentVertex) {
    /* If all vertices have been assigned a color, we are done */
    if (currentVertex == numVertices) {
        return true;
    }

    /* Try all colors for the current vertex */
    for (int color = 1; color <= numColors; color++) {
        /* Check if it is safe to assign this color to the vertex */
        if (isSafe(currentVertex, color, graph, colorAssignment)) {
            /* Assign the color and move on to the next vertex */
            colorAssignment[currentVertex] = color;
            if (colorVertices(graph, colorAssignment, numVertices, numColors, currentVertex+1)) {
                return true;
            }
            /* If this color does not lead to a solution, backtrack and try a different color */
            colorAssignment[currentVertex] = 0;
        }
    }
    /* If no color can be assigned to the vertex, return false */
    return false;
}

/* Function to print the color assignments */
void printColorAssignment(int colorAssignment[], int numVertices) {
    printf("\nThe vertex colors are: \n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i, colorAssignment[i]);
    }
}

int main() {
    // Define and populate the graph
    int numVertices, numEdges, u, v;
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};
    printf("Enter the number of vertices in the graph (<= 100): ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (vertex pairs separated by space):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // Define variables and get user input
    int numColors;
    int colorAssignment[MAX_VERTICES] = {0};
    printf("Enter the number of colors to use for coloring the graph: ");
    scanf("%d", &numColors);

    // Color the vertices recursively
    if (colorVertices(graph, colorAssignment, numVertices, numColors, 0)) {
        printf("\nGraph can be colored with %d colors!", numColors);
        printColorAssignment(colorAssignment, numVertices);
    }
    else {
        printf("\nGraph cannot be colored with %d colors.", numColors);
    }

    return 0;
}