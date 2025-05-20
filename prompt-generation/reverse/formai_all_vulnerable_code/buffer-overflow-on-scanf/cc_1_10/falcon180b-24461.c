//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define MAX_ITERATIONS 100

int num_vertices, num_colors;
int **graph;
int *color;

/* Function to initialize the graph and assign colors to vertices */
void init_graph() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = rand() % MAX_COLORS;
        }
    }
    color = (int *)malloc(num_vertices * sizeof(int));
    for (i = 0; i < num_vertices; i++) {
        color[i] = rand() % num_colors;
    }
}

/* Function to check if two vertices are adjacent */
int are_adjacent(int v1, int v2) {
    return graph[v1][v2]!= 0;
}

/* Function to print the current coloring of the graph */
void print_graph() {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if the current coloring is valid */
int is_valid() {
    int i, j, c;
    for (i = 0; i < num_vertices; i++) {
        c = color[i];
        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j] == c) {
                return 0;
            }
        }
    }
    return 1;
}

/* Function to color the graph using the backtracking algorithm */
void color_graph() {
    int i, j, k, c;
    for (i = 0; i < num_vertices; i++) {
        color[i] = i;
    }
    for (k = 0; k < MAX_ITERATIONS; k++) {
        for (i = 0; i < num_vertices; i++) {
            for (j = 0; j < num_vertices; j++) {
                if (are_adjacent(i, j)) {
                    if (color[i] == color[j]) {
                        color[i] = (color[i] + 1) % num_colors;
                        color[j] = (color[j] + 1) % num_colors;
                    }
                }
            }
        }
    }
}

/* Main function */
int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    graph = (int **)malloc(num_vertices * sizeof(int *));
    for (i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
    }
    init_graph();
    color_graph();
    printf("Initial coloring:\n");
    print_graph();
    return 0;
}