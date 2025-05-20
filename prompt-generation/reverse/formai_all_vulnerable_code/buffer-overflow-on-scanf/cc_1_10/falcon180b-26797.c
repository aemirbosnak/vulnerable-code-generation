//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int nvertices;

void init_graph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int v1, int v2) {
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

int get_color(int v) {
    return color[v];
}

void set_color(int v, int c) {
    color[v] = c;
}

int is_valid_color(int v, int c) {
    for (int i = 0; i < nvertices; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int color_graph() {
    int colors_used = 0;
    for (int i = 0; i < nvertices; i++) {
        if (color[i] == -1) {
            int c = rand() % MAX_COLORS;
            while (!is_valid_color(i, c)) {
                c = rand() % MAX_COLORS;
            }
            set_color(i, c);
            colors_used++;
        }
    }
    return colors_used;
}

int main() {
    srand(time(NULL));
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    nvertices = vertices;
    init_graph(vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            add_edge(i, j);
        }
    }
    int colors_used = color_graph();
    printf("Graph colored with %d colors\n", colors_used);
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d colored with %d\n", i, get_color(i));
    }
    return 0;
}