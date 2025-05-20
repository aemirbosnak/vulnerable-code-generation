//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
// This program demonstrates a solution to the Graph Coloring Problem using backtracking.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The GraphColoringProblem struct represents the graph coloring problem.
typedef struct GraphColoringProblem {
    int num_vertices;  // The number of vertices in the graph.
    int** adjacency_matrix;  // The adjacency matrix of the graph.
    int* colors;  // The colors of the vertices.
    int min_colors;  // The minimum number of colors needed to color the graph.
} GraphColoringProblem;

// Create a new graph coloring problem.
GraphColoringProblem* create_graph_coloring_problem(int num_vertices) {
    GraphColoringProblem* problem = malloc(sizeof(GraphColoringProblem));
    problem->num_vertices = num_vertices;
    problem->adjacency_matrix = malloc(sizeof(int*) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        problem->adjacency_matrix[i] = malloc(sizeof(int) * num_vertices);
    }
    problem->colors = malloc(sizeof(int) * num_vertices);
    problem->min_colors = -1;
    return problem;
}

// Free the memory allocated for the graph coloring problem.
void free_graph_coloring_problem(GraphColoringProblem* problem) {
    for (int i = 0; i < problem->num_vertices; i++) {
        free(problem->adjacency_matrix[i]);
    }
    free(problem->adjacency_matrix);
    free(problem->colors);
    free(problem);
}

// Read the graph coloring problem from a file.
GraphColoringProblem* read_graph_coloring_problem(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int num_vertices;
    fscanf(file, "%d", &num_vertices);

    GraphColoringProblem* problem = create_graph_coloring_problem(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            fscanf(file, "%d", &problem->adjacency_matrix[i][j]);
        }
    }

    fclose(file);

    return problem;
}

// Write the graph coloring problem to a file.
void write_graph_coloring_problem(GraphColoringProblem* problem, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%d\n", problem->num_vertices);

    for (int i = 0; i < problem->num_vertices; i++) {
        for (int j = 0; j < problem->num_vertices; j++) {
            fprintf(file, "%d ", problem->adjacency_matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Check if a vertex is valid to color with a given color.
bool is_valid_color(GraphColoringProblem* problem, int vertex, int color) {
    for (int i = 0; i < problem->num_vertices; i++) {
        if (problem->adjacency_matrix[vertex][i] == 1 && problem->colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Color a vertex with a given color.
void color_vertex(GraphColoringProblem* problem, int vertex, int color) {
    problem->colors[vertex] = color;
}

// Uncolor a vertex.
void uncolor_vertex(GraphColoringProblem* problem, int vertex) {
    problem->colors[vertex] = -1;
}

// Find the minimum number of colors needed to color the graph.
int find_minimum_colors(GraphColoringProblem* problem) {
    if (problem->min_colors != -1) {
        return problem->min_colors;
    }

    int min_colors = problem->num_vertices;

    for (int i = 0; i < problem->num_vertices; i++) {
        if (problem->colors[i] == -1) {
            for (int color = 0; color < problem->num_vertices; color++) {
                if (is_valid_color(problem, i, color)) {
                    color_vertex(problem, i, color);
                    int num_colors = find_minimum_colors(problem);
                    if (num_colors < min_colors) {
                        min_colors = num_colors;
                    }
                    uncolor_vertex(problem, i);
                }
            }
        }
    }

    problem->min_colors = min_colors;

    return min_colors;
}

// Print the graph coloring problem.
void print_graph_coloring_problem(GraphColoringProblem* problem) {
    printf("Number of vertices: %d\n", problem->num_vertices);
    printf("Adjacency matrix:\n");
    for (int i = 0; i < problem->num_vertices; i++) {
        for (int j = 0; j < problem->num_vertices; j++) {
            printf("%d ", problem->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Colors:\n");
    for (int i = 0; i < problem->num_vertices; i++) {
        printf("%d ", problem->colors[i]);
    }
    printf("\n");
    printf("Minimum number of colors: %d\n", problem->min_colors);
}

// The main function.
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    GraphColoringProblem* problem = read_graph_coloring_problem(argv[1]);
    if (problem == NULL) {
        return 1;
    }

    int min_colors = find_minimum_colors(problem);

    printf("Minimum number of colors: %d\n", min_colors);

    free_graph_coloring_problem(problem);

    return 0;
}