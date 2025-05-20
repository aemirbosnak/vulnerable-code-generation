//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

// define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// define the maximum number of colors that we can use for coloring the vertices
#define MAX_COLORS 10

// define the adjacency matrix to represent the graph
int graph[MAX_VERTICES][MAX_VERTICES];

// define the number of vertices in the graph
int num_vertices;

// define the array to store the color assigned to each vertex
int colors[MAX_VERTICES];

// define the function to check if it is possible to assign a color 'c' to vertex 'v'
int is_color_possible(int v, int c) {
    // check if any adjacent vertex has already been assigned the color 'c'
    for(int i=0; i<num_vertices; i++) {
        if(graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    // if no adjacent vertex has already been assigned the color 'c', return 1
    return 1;
}

// define the function to color the vertices of the graph
int color_graph(int v) {
    // base case: if all vertices have been colored, return 1
    if(v == num_vertices) {
        return 1;
    }
    // try to assign a color to the current vertex 'v'
    for(int c=1; c<=MAX_COLORS; c++) {
        // check if it is possible to assign the color 'c' to the vertex 'v'
        if(is_color_possible(v, c)) {
            // assign the color 'c' to the vertex 'v'
            colors[v] = c;
            // recursively color the remaining vertices
            if(color_graph(v+1)) {
                return 1;
            }
            // backtrack: undo the color assignment to vertex 'v'
            colors[v] = 0;
        }
    }
    // if no color can be assigned to the vertex 'v', return 0
    return 0;
}

// define the main function
int main() {
    // read the number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    // read the adjacency matrix for the graph
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i=0; i<num_vertices; i++) {
        for(int j=0; j<num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // color the vertices of the graph
    if(color_graph(0)) {
        // print the colors assigned to the vertices of the graph
        printf("The vertices are colored using the following colors:\n");
        for(int i=0; i<num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
        }
    } else {
        // if it is impossible to color the vertices of the graph using at most 'MAX_COLORS' colors
        printf("It is impossible to color the vertices of the graph using at most %d colors.\n", MAX_COLORS);
    }
    return 0;
}