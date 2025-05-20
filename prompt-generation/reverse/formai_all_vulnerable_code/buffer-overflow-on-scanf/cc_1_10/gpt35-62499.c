//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representation of graph

// function to print the color assignment for vertices
void printColors(int colors[], int numVertices) {
    printf("Color assignment:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

// function to check if it's safe to assign color c to vertex v
bool isSafe(int colors[], int numVertices, int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// recursive function to solve graph coloring problem
bool graphColorUtil(int colors[], int numVertices, int numColors, int v) {
    if (v == numVertices) {
        return true; // all vertices have been assigned a color
    }

    for (int c = 1; c <= numColors; c++) { // try all possible colors for vertex v
        if (isSafe(colors, numVertices, v, c)) {
            colors[v] = c; // assign color c to vertex v
            if (graphColorUtil(colors, numVertices, numColors, v+1)) {
                return true;
            }
            colors[v] = 0; // backtrack
        }
    }
    return false; // no solution found
}

// function to solve graph coloring problem
bool graphColoring(int numVertices, int numColors) {
    int colors[numVertices];
    for (int i = 0; i < numVertices; i++) {
        colors[i] = 0; // initialize all vertices to have no color assigned
    }

    if (!graphColorUtil(colors, numVertices, numColors, 0)) {
        printf("No solution exists\n");
        return false;
    }

    printColors(colors, numVertices);
    return true;
}

int main() {
    int numVertices;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter adjacency matrix of graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int numColors;
    printf("Enter number of colors to use: ");
    scanf("%d", &numColors);

    printf("\n");

    graphColoring(numVertices, numColors);
    return 0;
}