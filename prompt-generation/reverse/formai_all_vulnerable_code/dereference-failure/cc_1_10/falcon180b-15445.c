//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int num_colors;
int *color_map;

void init_graph(int n) {
    num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int get_neighbors(int vertex, int *neighbors) {
    int count = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1) {
            neighbors[count++] = i;
        }
    }
    return count;
}

int is_valid_color(int vertex, int color, int *color_map) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1 && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int start_vertex) {
    int *color_map = malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        color_map[i] = -1;
    }
    color_map[start_vertex] = 0;
    int num_colored = 1;
    while (num_colored < num_vertices) {
        int max_neighbors = 0;
        int next_vertex = -1;
        for (int i = 0; i < num_vertices; i++) {
            if (color_map[i] == -1 && max_neighbors <= get_neighbors(i, graph[i])) {
                max_neighbors = get_neighbors(i, graph[i]);
                next_vertex = i;
            }
        }
        if (next_vertex == -1) {
            break;
        }
        for (int color = 0; color < num_colors; color++) {
            if (is_valid_color(next_vertex, color, color_map)) {
                color_map[next_vertex] = color;
                num_colored++;
                break;
            }
        }
    }
    return num_colors;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    int num_colors = color_graph(0);
    printf("Graph colored with %d colors.\n", num_colors);
    return 0;
}