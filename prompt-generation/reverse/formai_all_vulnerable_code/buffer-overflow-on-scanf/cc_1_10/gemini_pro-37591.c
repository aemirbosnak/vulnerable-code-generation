//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Graph Coloring Problem
// Given a graph and a set of colors, find a way to color the graph such that no two adjacent vertices have the same color.

// A graph is represented as an adjacency matrix.
int graph[100][100];

// A set of colors is represented as an array.
int colors[100];

// The number of vertices in the graph.
int n;

// The number of colors in the set.
int m;

// Function to check if the graph is colored properly.
int is_colored_properly() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 1 && colors[i] == colors[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the colored graph.
void print_colored_graph() {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d is colored %d\n", i, colors[i]);
    }
}

// Function to solve the graph coloring problem.
int solve_graph_coloring_problem() {
    // Initialize the colors of all vertices to 0.
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }

    // Try all possible colors for the first vertex.
    for (int i = 1; i <= m; i++) {
        colors[0] = i;

        // Recursively try all possible colors for the remaining vertices.
        if (solve_graph_coloring_problem_recursive(1)) {
            return 1;
        }
    }

    // If no solution is found, return 0.
    return 0;
}

// Recursive function to solve the graph coloring problem.
int solve_graph_coloring_problem_recursive(int vertex) {
    // If all vertices are colored, return 1.
    if (vertex == n) {
        return 1;
    }

    // Try all possible colors for the current vertex.
    for (int i = 1; i <= m; i++) {
        // Check if the current color is valid for the current vertex.
        int is_valid = 1;
        for (int j = 0; j < vertex; j++) {
            if (graph[vertex][j] == 1 && colors[vertex] == colors[j]) {
                is_valid = 0;
                break;
            }
        }

        // If the current color is valid, assign it to the current vertex and recursively solve the problem for the next vertex.
        if (is_valid) {
            colors[vertex] = i;
            if (solve_graph_coloring_problem_recursive(vertex + 1)) {
                return 1;
            }
        }
    }

    // If no valid color is found for the current vertex, return 0.
    return 0;
}

// Main function.
int main() {
    // Get the input.
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the number of colors in the set: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Solve the graph coloring problem.
    int is_colored = solve_graph_coloring_problem();

    // Print the result.
    if (is_colored) {
        printf("The graph is colored properly.\n");
        print_colored_graph();
    } else {
        printf("The graph cannot be colored properly.\n");
    }

    return 0;
}