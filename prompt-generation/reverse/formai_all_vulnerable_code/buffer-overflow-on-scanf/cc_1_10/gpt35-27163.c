//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_COLORS 5

int graph[MAX_NODES][MAX_NODES] = {0}; // adjacency matrix representation of graph
int color[MAX_NODES] = {0}; // color assigned to each node
int num_nodes;

// function to check if a vertex can be colored with the given color
int is_color_valid(int vertex, int c) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

// function to solve graph coloring problem using backtracking
int graph_coloring(int vertex, int max_colors) {
    if (vertex == num_nodes) {
        return 1; // all vertices have been assigned a color
    }
    for (int c = 1; c <= max_colors; c++) {
        if (is_color_valid(vertex, c)) {
            color[vertex] = c; // assign color to vertex
            if (graph_coloring(vertex+1, max_colors)) {
                return 1; // solution found
            }
            color[vertex] = 0; // backtrack
        }
    }
    return 0; // no solution found
}

int main() {
    // initialize graph
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // solve graph coloring problem
    int max_colors = MAX_COLORS; // maximum number of colors
    while (!graph_coloring(0, max_colors)) {
        max_colors++; // increment number of colors
    }
    // print solution
    printf("Minimum number of colors required: %d\n", max_colors);
    printf("Assigned colors:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: Color %d\n", i+1, color[i]);
    }
    return 0;
}