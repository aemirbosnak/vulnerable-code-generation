//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int vertices;                        // number of vertices in the graph
bool adj_matrix[MAX_VERTICES][MAX_VERTICES];  // adjacency matrix representing the graph
int colors[MAX_VERTICES];            // array to store the colors assigned to each vertex

// function prototypes
bool is_safe(int vertex, int color);
bool graph_coloring(int vertex);

// function to print the solution
void print_solution() {
    printf("\nSolution:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
}

// main function
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    // initialize all vertices with no color
    for (int i = 0; i < vertices; i++) {
        colors[i] = 0;   // 0 means no color
    }

    // start the search from vertex 0
    if (graph_coloring(0)) {
        print_solution();
        return 0;
    } else {
        printf("No solution found!\n");
        return 1;
    }
}

// function to check if a color is safe for a given vertex
bool is_safe(int vertex, int color) {
    for (int i = 0; i < vertices; i++) {
        if (adj_matrix[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// function to recursively solve the Graph Coloring Problem using backtracking
bool graph_coloring(int vertex) {
    // base case: all vertices have colors assigned
    if (vertex == vertices) {
        return true;
    }

    // try all possible colors for the current vertex
    for (int color = 1; color <= vertices; color++) {
        if (is_safe(vertex, color)) {
            colors[vertex] = color;
            // move to the next vertex
            if (graph_coloring(vertex + 1)) {
                return true;   // solution found
            }
            // backtrack and try with a different color
            colors[vertex] = 0;
        }
    }

    // no solution found
    return false;
}