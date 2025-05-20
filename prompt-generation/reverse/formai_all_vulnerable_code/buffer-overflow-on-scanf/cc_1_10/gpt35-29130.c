//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices for our graph

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]; // The adjacency matrix
int num_vertices; // The number of vertices in the graph

bool is_safe(int vertex, int color, int colors[])
{
    for (int i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[vertex][i] && colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool graph_coloring_helper(int vertices[], int colors[], int vertex_index)
{
    // If all vertices are assigned colors, return true
    if (vertex_index == num_vertices) {
        return true;
    }

    // Choose a vertex and try assigning all possible colors
    for (int i = 1; i <= 4; i++) {
        if (is_safe(vertices[vertex_index], i, colors)) {
            colors[vertices[vertex_index]] = i;

            // Recursively assign colors to the remaining vertices
            if (graph_coloring_helper(vertices, colors, vertex_index + 1)) {
                return true;
            }

            // If assigning this color didn't lead to a solution,
            // unassign it and try the next one
            colors[vertices[vertex_index]] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

bool graph_coloring(int vertices[])
{
    int colors[MAX_VERTICES] = { 0 };

    // Call the helper function to solve the graph coloring problem
    if (graph_coloring_helper(vertices, colors, 0)) {
        // Print the solution
        printf("The vertices are colored as follows:\n");

        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }

        // Solution found, return true
        return true;
    }

    // No solution found
    return false;
}

int main()
{
    // Prompt the user to enter the number of vertices for the graph
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);

    scanf("%d", &num_vertices);

    printf("\n");

    // Prompt the user to enter the adjacency matrix for the graph
    printf("Enter the adjacency matrix for the graph (1 for connected, 0 for not connected):\n");

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("\n");

    // Create an array of vertex indices
    int vertices[MAX_VERTICES];

    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = i;
    }

    // Call the graph coloring function and print the result
    if (graph_coloring(vertices)) {
        printf("Graph can be colored using only 4 colors.\n");
    } else {
        printf("Graph cannot be colored using only 4 colors.\n");
    }

    return 0;
}