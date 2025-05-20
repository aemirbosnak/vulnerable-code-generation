//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAXVERTICES 100

int map[MAXVERTICES][MAXVERTICES]; // adjacency matrix
int colors[MAXVERTICES]; // each element represents a vertex's color
int vertices, edges;

// function to check if a color assignment is valid
int isSafe(int vertex, int color) {
    for (int i = 0; i < vertices; i++) {
        if (map[vertex][i] && colors[i] == color) { // if adjacent vertex i has same color
            return 0;
        }
    }
    return 1; // color assignment is valid
}

// recursive function to assign colors to vertices
int graphColoring(int vertex, int numColors) {
    if (vertex == vertices) { // all vertices have been colored
        return 1;
    }
    for (int i = 1; i <= numColors; i++) { // try all possible colors
        if (isSafe(vertex, i)) { // if color assignment is valid
            colors[vertex] = i; // assign the color to the vertex
            if (graphColoring(vertex+1, numColors)) { // recursively try to color the next vertex
                return 1;
            }
            colors[vertex] = 0; // backtrack: undo the color assignment
        }
    }
    return 0; // could not color the graph with numColors
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the pairs of vertices that represent edges:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        map[u][v] = map[v][u] = 1; // set adjacency between vertices
    }
    printf("Enter the maximum number of colors: ");
    int numColors;
    scanf("%d", &numColors);
    if (graphColoring(0, numColors)) {
        printf("The graph can be colored with %d colors as follows: \n", numColors);
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors", numColors);
    }
    return 0;
}