//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int num_vertices;
int **graph;
int *color;

bool is_safe(int v, int c, int *color, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool backtrack(int v, int c, int *color, int num_vertices) {
    if (v == num_vertices) {
        return true;
    }

    for (int i = 1; i <= MAX_COLORS; i++) {
        if (is_safe(v, i, color, num_vertices)) {
            color[v] = i;
            if (backtrack(v + 1, i, color, num_vertices)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    graph = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    color = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        color[i] = -1;
    }

    int num_colors = backtrack(0, 1, color, num_vertices);

    printf("Minimum number of colors needed: %d\n", num_colors);

    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", color[i] + 1);
    }

    for (int i = 0; i < num_vertices; i++) {
        free(graph[i]);
    }
    free(graph);
    free(color);

    return 0;
}