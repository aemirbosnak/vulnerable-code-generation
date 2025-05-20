//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>

#define MAXVERTICES 100
#define MAXCOLORS 10

int numVertices;
int graph[MAXVERTICES][MAXVERTICES];
int assignedColors[MAXVERTICES];

void readGraph() {
    int i, j;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function to check if it is safe to color a vertex with given color
int isSafe(int v, int c) {
    int i;
    for (i = 0; i < numVertices; i++) {
        if (graph[v][i] && assignedColors[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to assign colors to vertices
int assignColors(int v) {
    int c;
    if (v == numVertices) {
        return 1; // all vertices have been assigned colors
    }
    for (c = 1; c <= MAXCOLORS; c++) {
        if (isSafe(v, c)) {
            assignedColors[v] = c; // assign color c to vertex v
            if (assignColors(v + 1)) {
                return 1; // color assignment successful
            }
            assignedColors[v] = 0; // backtrack
        }
    }
    return 0; // color assignment failed
}

int main() {
    int i;
    readGraph();
    if (assignColors(0)) {
        printf("Coloring of graph successful!\n"
               "Assigned colors are: ");
        for (i = 0; i < numVertices; i++) {
            printf("%d ", assignedColors[i]);
        }
        printf("\n");
    } else {
        printf("Coloring of graph failed!");
    }

    return 0;
}