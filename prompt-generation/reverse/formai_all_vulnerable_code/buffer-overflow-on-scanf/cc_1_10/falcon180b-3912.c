//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 100

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int num_colors;

void generate_graph(int num_vertices, int num_colors) {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (i!= j) {
                graph[i][j] = rand() % num_colors;
            } else {
                graph[i][j] = 0;
            }
        }
    }
}

int is_valid(int vertex, int color, int num_colors, int *color_map) {
    int i;
    for (i = 0; i < num_colors; i++) {
        if ((color_map[vertex] == i) || (color_map[vertex] == -color)) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int num_vertices, int num_colors, int *color_map) {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        color_map[i] = i;
    }
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j]!= 0) {
                if (!is_valid(i, graph[i][j], num_colors, color_map)) {
                    printf("Invalid color %d at vertex %d\n", graph[i][j], i);
                    exit(1);
                }
                if (!is_valid(j, graph[i][j], num_colors, color_map)) {
                    printf("Invalid color %d at vertex %d\n", graph[i][j], j);
                    exit(1);
                }
            }
        }
    }
    printf("Colored graph:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, color_map[i]);
    }
}

int main() {
    int num_vertices, num_colors;
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of colors: ");
    scanf("%d", &num_colors);
    srand(time(NULL));
    generate_graph(num_vertices, num_colors);
    int color_map[num_vertices];
    color_graph(num_vertices, num_colors, color_map);
    return 0;
}