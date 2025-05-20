//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 5000
#define MAX_COLORS 10

int num_vertices, num_edges;
int links[MAX_EDGES][2];
int color[MAX_VERTICES];
bool is_colored[MAX_VERTICES];
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
bool is_possible = true;

void print_solution() {
    printf("\nThe colors are: \n");
    for(int i=0;i<num_vertices;++i) {
        printf("Vertex %d: color %d\n", i+1, color[i]);
    }
}

bool is_safe_to_color(int vertex, int current_color) {
    // Check if any adjacent vertex is already colored with the current color
    for(int i=0;i<num_vertices;++i) {
        if(adj_matrix[vertex][i]) {
            if(is_colored[i] && color[i]==current_color) {
                return false;
            }
        }
    }
    return true;
}

void graph_coloring(int vertex) {
    // Base case
    if(vertex == num_vertices) {
        print_solution();
        is_possible=true; // Set it to true in case there are multiple solutions and we want to continue finding them
        return;
    }
    // Try all possible colors for the current vertex
    for(int c=1;c<=MAX_COLORS;++c) {
        // Check if it is safe to color with color c
        if(is_safe_to_color(vertex, c)) {
            color[vertex] = c;
            is_colored[vertex] = true;
            // Move to the next vertex
            graph_coloring(vertex+1);
            if(is_possible) {
                return; // If we have found a solution, stop processing
            }
            // Backtrack
            is_colored[vertex] = false;
        }
    }
    is_possible = false;
}

int main() {
    printf("Enter the number of vertices and edges (separated by space): ");
    scanf("%d %d", &num_vertices, &num_edges);
    printf("Enter the edges (source, destination): ");
    // Build the adjacency matrix from edge list
    for(int i=0;i<num_edges;++i) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        adj_matrix[src-1][dst-1] = adj_matrix[dst-1][src-1] = 1;
    }
    graph_coloring(0);
    if(!is_possible) {
        printf("No solution exists.\n");
    }
    return 0;
}