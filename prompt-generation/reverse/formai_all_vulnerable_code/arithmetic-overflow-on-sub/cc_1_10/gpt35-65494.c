//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of colors */
#define MAX_COLORS 6

/* Define the maximum number of vertices */
#define MAX_VERTICES 10

/* Define the adjacency matrix for the graph */
int adj_mtx[MAX_VERTICES][MAX_VERTICES];

/* Define the current colors assigned to vertices */
int colors[MAX_VERTICES];

/* Define the number of vertices and edges */
int num_vertices, num_edges;

/* Define the function to check whether a vertex can be assigned a certain color */
int is_color_valid(int vertex, int color) {
    int i;
    for(i=0; i<num_vertices; i++) {
        if(adj_mtx[vertex][i] && color==colors[i]) {
            return 0;
        }
    }
    return 1;
}

/* Define the function to assign colors to the vertices */
void assign_colors(int vertex, int num_colors) {
    int i, j, color;
    /* Base case: reached the end of the graph */
    if(vertex==num_vertices) {
        printf("\nThe graph can be colored as:\n");
        for(i=0; i<num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
        }
        return;
    }
    /* Try different colors for the current vertex */
    for(color=1; color<=num_colors; color++) {
        if(is_color_valid(vertex, color)) {
            colors[vertex] = color;
            /* Recursively assign colors to the rest of the vertices */
            assign_colors(vertex+1, num_colors);
            colors[vertex] = 0;
        }
    }
}

int main() {
    int i, j, v1, v2;
    /* Ask user for the number of vertices and edges */
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    /* Initialize the adjacency matrix */
    for(i=0; i<num_vertices; i++) {
        for(j=0; j<num_vertices; j++) {
            adj_mtx[i][j] = 0;
        }
    }
    /* Ask user for the edges */
    for(i=0; i<num_edges; i++) {
        printf("Enter the edges for %d: ", i+1);
        scanf("%d%d", &v1, &v2);
        adj_mtx[v1-1][v2-1] = 1;
        adj_mtx[v2-1][v1-1] = 1;
    }
    /* Initialize the colors of the vertices to 0 */
    for(i=0; i<num_vertices; i++) {
        colors[i] = 0;
    }
    /* Assign colors to the vertices using backtracking */
    assign_colors(0, MAX_COLORS);
    /* Return 0 to indicate successful completion of the program */
    return 0;
}