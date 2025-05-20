//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int colors[MAX_VERTICES]; // colors of each vertex
int vertices, edges; // number of vertices and edges
int numColors; // number of available colors

// function to check if a color can be used for a vertex
int isSafe(int vertex, int color) {
    for(int i = 0; i < vertices; i++) {
        if(graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// recursive function to color the vertices
int colorVertices(int vertex) {
    // base case: all vertices have been colored
    if(vertex == vertices) {
        return 1;
    }

    // try to color the vertex with each available color
    for(int i = 0; i < numColors; i++) {
        if(isSafe(vertex, i)) {
            colors[vertex] = i;

            // recursively color the next vertex
            if(colorVertices(vertex + 1)) {
                return 1;
            }

            // if coloring the next vertex fails, backtrack and try a different color
            colors[vertex] = -1;
        }
    }

    // if all colors have been tried and none work, return 0 to backtrack
    return 0;
}

int main() {
    // get input
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // initialize colors to -1 (not colored)
    for(int i = 0; i < vertices; i++) {
        colors[i] = -1;
    }

    // determine the maximum number of colors needed
    numColors = 0;
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if(graph[i][j] && colors[i] == colors[j]) {
                colors[i] = -1;
                break;
            }
        }
        if(colors[i] == -1) {
            numColors += 1;
        }
    }

    // try to color the vertices
    if(colorVertices(0)) {
        // print the colors of each vertex
        printf("The vertices can be colored with at most %d colors:\n", numColors);
        for(int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    }
    else {
        printf("The vertices cannot be colored with less than %d colors.\n", numColors);
    }

    return 0;
}