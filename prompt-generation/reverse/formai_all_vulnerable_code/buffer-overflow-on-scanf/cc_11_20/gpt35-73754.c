//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 1000000
#define MAX_COLORS 10

int colors[MAX_VERTICES];
int adj_matrix[MAX_VERTICES][MAX_VERTICES];

int main() {
    int num_vertices, num_edges;
    printf("How many vertices does your graph have? ");
    scanf("%d", &num_vertices);
    printf("How many edges does your graph have? ");
    scanf("%d", &num_edges);
    if (num_vertices < 1 || num_vertices > MAX_VERTICES ||
        num_edges < num_vertices - 1 || num_edges > MAX_EDGES) {
        printf("Invalid input.\n");
        return 1;
    }
    srand(time(NULL));
    // connect vertices in a random tree
    for (int i = 1; i < num_vertices; i++) {
        int parent = rand() % i;
        adj_matrix[i][parent] = adj_matrix[parent][i] = 1;
    }
    // add remaining edges at random
    for (int i = num_vertices - 1; i < num_edges; i++) {
        int u = rand() % num_vertices, v = rand() % num_vertices;
        if (u != v && !adj_matrix[u][v]) {
            adj_matrix[u][v] = adj_matrix[v][u] = 1;
        }
    }
    // initialize all vertices to no color
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }
    int num_colors = 0;
    // assign colors to vertices
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            int possible_colors[MAX_COLORS] = {0};
            // find colors of neighboring vertices
            for (int j = 0; j < num_vertices; j++) {
                if (adj_matrix[i][j] && colors[j] != -1) {
                    possible_colors[colors[j]] = 1;
                }
            }
            // choose first available color
            for (int j = 0; j < MAX_COLORS; j++) {
                if (!possible_colors[j]) {
                    colors[i] = j;
                    if (j >= num_colors) {
                        num_colors = j + 1;
                    }
                    break;
                }
            }
            // if no color available, add a new one
            if (colors[i] == -1) {
                colors[i] = num_colors++;
            }
        }
    }
    printf("Your graph has been colored with %d colors:\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: color %d\n", i, colors[i]);
    }
    return 0;
}