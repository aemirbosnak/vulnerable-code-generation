//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int num_colors;

void init_graph(int n) {
    num_vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int is_valid_coloring(int vertex, int color, int colors[]) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_vertex(int vertex, int color, int colors[]) {
    colors[vertex] = color;
}

int get_next_color(int colors[], int num_colors) {
    for (int i = 0; i < num_colors; i++) {
        if (colors[i] == -1) {
            return i;
        }
    }
    return -1;
}

void graph_coloring(int num_colors) {
    int colors[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }
    int num_colored = 0;
    int color = 0;
    while (num_colored < num_vertices) {
        int vertex = -1;
        for (int i = 0; i < num_vertices; i++) {
            if (colors[i] == -1 && vertex == -1) {
                vertex = i;
            }
        }
        if (vertex == -1) {
            break;
        }
        int next_color = get_next_color(colors, num_colors);
        if (next_color == -1) {
            break;
        }
        color++;
        color_vertex(vertex, next_color, colors);
        num_colored++;
    }
    if (num_colored == num_vertices) {
        printf("Graph is k-colorable with k = %d\n", num_colors);
    } else {
        printf("Graph is not k-colorable with k = %d\n", num_colors);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init_graph(n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int num_colors;
    scanf("%d", &num_colors);
    graph_coloring(num_colors);
    return 0;
}