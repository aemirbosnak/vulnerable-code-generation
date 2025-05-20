//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 1000

// Graph representation using adjacency matrix
int **graph;
int num_vertices, num_colors;

// Function to initialize the graph with random values
void init_graph() {
    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

// Function to print the graph
void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two vertices are adjacent
bool are_adjacent(int vertex1, int vertex2) {
    return graph[vertex1][vertex2] == 1;
}

// Function to check if a vertex is adjacent to any other vertex
bool is_connected(int vertex) {
    for (int i = 0; i < num_vertices; i++) {
        if (are_adjacent(vertex, i) && i!= vertex) {
            return true;
        }
    }
    return false;
}

// Function to color the graph using backtracking algorithm
bool color_graph(int vertex, int color) {
    if (vertex >= num_vertices) {
        return true;
    }

    // Try all possible colors
    for (int i = 0; i < num_colors; i++) {
        graph[vertex][i] = 1;
        if (color_graph(vertex + 1, i + 1)) {
            return true;
        }
        graph[vertex][i] = 0;
    }

    return false;
}

// Function to solve the graph coloring problem
void solve_graph_coloring_problem() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    graph = (int **)malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(sizeof(int) * num_colors);
        for (int j = 0; j < num_colors; j++) {
            graph[i][j] = 0;
        }
    }

    init_graph();
    printf("Initial graph:\n");
    print_graph();

    if (color_graph(0, 0)) {
        printf("Graph is %d-colorable.\n", num_colors);
    } else {
        printf("Graph is not %d-colorable.\n", num_colors);
    }
}

int main() {
    solve_graph_coloring_problem();
    return 0;
}