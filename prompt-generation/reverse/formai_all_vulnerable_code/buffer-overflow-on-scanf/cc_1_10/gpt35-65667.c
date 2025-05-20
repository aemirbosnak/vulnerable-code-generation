//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
// The Case of the Missing Colors
// Detective Sherlock Holmes is on the case to solve a graph coloring problem

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 26  // Maximum number of vertices in the graph
#define MAX_COLORS 5     // Maximum number of colors that can be used

// Function declarations
void read_graph(int graph[][MAX_VERTICES], int *num_vertices);
void print_graph(int graph[][MAX_VERTICES], int num_vertices);
void graph_coloring(int num_vertices, int graph[][MAX_VERTICES], int colors[], int num_colors);
bool check_valid_coloring(int num_vertices, int graph[][MAX_VERTICES], int colors[]);
bool graph_coloring_helper(int num_vertices, int graph[][MAX_VERTICES], int colors[], int num_colors, int current_vertex);

// Function to read the graph from input
void read_graph(int graph[][MAX_VERTICES], int *num_vertices) {
    char s[MAX_VERTICES];
    int row, col;
    printf("Enter the number of vertices: ");
    scanf("%d", num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (row = 0; row < *num_vertices; row++) {
        scanf("%s", s);
        for (col = 0; col < *num_vertices; col++) {
            graph[row][col] = s[col] - '0';
        }
    }
}

// Function to print the graph
void print_graph(int graph[][MAX_VERTICES], int num_vertices) {
    int row, col;
    printf("The adjacency matrix representation of the graph is:\n");
    for (row = 0; row < num_vertices; row++) {
        for (col = 0; col < num_vertices; col++) {
            printf("%d ", graph[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the coloring is valid
bool check_valid_coloring(int num_vertices, int graph[][MAX_VERTICES], int colors[]) {
    int row, col;
    for (row = 0; row < num_vertices; row++) {
        for (col = 0; col < num_vertices; col++) {
            if (graph[row][col] && (colors[row] == colors[col])) {
                return false;
            }
        }
    }
    return true;
}

// A recursive function to find the coloring of the graph
bool graph_coloring_helper(int num_vertices, int graph[][MAX_VERTICES], int colors[], int num_colors, int current_vertex) {
    int next_vertex;
    bool valid_coloring;
    if (current_vertex == num_vertices) { // Base case: All vertices have been colored
        valid_coloring = check_valid_coloring(num_vertices, graph, colors);
        if (valid_coloring) {
            printf("The graph can be colored with %d colors. The colors of the vertices are:\n", num_colors);
            for (next_vertex = 0; next_vertex < num_vertices; next_vertex++) {
                printf("%c: %d\n", 'A' + next_vertex, colors[next_vertex] + 1);
            }
            return true;
        }
        return false;
    }
    for (next_vertex = 0; next_vertex < num_colors; next_vertex++) {  // Trying all possible colors for the current vertex
        colors[current_vertex] = next_vertex;  // Assign a color to the current vertex
        if (graph_coloring_helper(num_vertices, graph, colors, num_colors, current_vertex + 1)) { // Recursively try to color the next vertex
            return true;
        }
    }
    return false;
}

// Main function to find the minimum number of colors needed to color a graph without any two adjacent vertices having the same color
void graph_coloring(int num_vertices, int graph[][MAX_VERTICES], int colors[], int num_colors) {
    int start_vertex = 0;
    bool valid_coloring;
    while (!valid_coloring) {  // Keep incrementing the number of colors until a valid coloring is found
        printf("Trying to color the graph with %d colors...\n", num_colors);
        valid_coloring = graph_coloring_helper(num_vertices, graph, colors, num_colors, start_vertex);
        if (!valid_coloring) {
            printf("Coloring with %d colors failed.\n", num_colors);
            num_colors++;
        }
    }
}

// Main function to read the graph, find the minimum number of colors needed to color it and print the results
int main() {
    printf("**************************\n");
    printf("* The Case of the Missing Colors *\n");
    printf("**************************\n\n");
    int graph[MAX_VERTICES][MAX_VERTICES], num_vertices, colors[MAX_VERTICES], num_colors = 2;
    memset(graph, 0, sizeof(graph));  // Initializing the graph with 0
    read_graph(graph, &num_vertices);
    print_graph(graph, num_vertices);
    graph_coloring(num_vertices, graph, colors, num_colors);
    return 0;
}