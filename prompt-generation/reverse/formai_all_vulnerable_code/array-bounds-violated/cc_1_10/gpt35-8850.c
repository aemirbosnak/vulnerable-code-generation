//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum number of vertices

int graph[MAX][MAX]; // Defining graph as a 2D array
int color[MAX]; // To store the color of each vertex
 
void display_colors(int num_vertices) {
    printf("The colors assigned to the vertices are:\n");
    for(int i=0; i<num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, color[i]);
    }
}
 
int is_safe(int vertex, int num_vertices, int cur_color) {
    for(int i=0; i<num_vertices; i++) {
        if(graph[vertex][i] && cur_color == color[i]) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}
 
int graph_coloring(int vertex, int num_vertices, int num_colors) {

    if(vertex == num_vertices) { // All vertices are colored
        return 1;
    }
 
    for(int cur_color=1; cur_color<=num_colors; cur_color++) {
        if(is_safe(vertex, num_vertices, cur_color)) {
            color[vertex] = cur_color;
            if(graph_coloring(vertex+1, num_vertices, num_colors)) {
                return 1;
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return 0; // Solution not possible
}
 
int main() {

    int num_vertices, num_edges, vertex1, vertex2, num_colors;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("Enter the edges in the graph:\n");
    for(int i=0; i<num_edges; i++) { // Taking input for all edges
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1-1][vertex2-1] = 1; // Assigning the vertices as 1 to num_vertices
        graph[vertex2-1][vertex1-1] = 1; // Making the graph undirected
    }

    printf("Enter the number of colors to be used: ");
    scanf("%d", &num_colors);

    // Initializing all vertex colors as 0
    for(int i=0; i<num_vertices; i++) {
        color[i] = 0;
    }

    printf("\nColoring the graph...\n\n");
    if(graph_coloring(0, num_vertices, num_colors)) {
        display_colors(num_vertices); // If a solution is possible, display the colors
    }
    else {
        printf("Solution not possible!\n"); // If a solution is not possible
    }
    return 0;
}