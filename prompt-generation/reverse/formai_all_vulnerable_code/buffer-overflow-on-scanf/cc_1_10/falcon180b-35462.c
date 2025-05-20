//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

int num_vertices;
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

void generate_graph() {
    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            graph[i][j] = rand() % 2;
            graph[j][i] = graph[i][j];
        }
    }
}

int is_valid_coloring(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int vertex = 0;
    int color = 1;
    while (vertex < num_vertices) {
        if (is_valid_coloring(vertex, color)) {
            colors[vertex] = color;
            vertex++;
        } else {
            color++;
        }
    }
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d -- %d\n", i, j);
            }
        }
    }
}

void print_colors() {
    printf("Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Graph:\n");
    print_graph();

    generate_graph();
    color_graph();

    printf("Colors:\n");
    print_colors();

    return 0;
}