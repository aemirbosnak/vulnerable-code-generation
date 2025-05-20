//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 4

int vertices;
int edges;
int colors;

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init_graph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void print_graph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void init_colors() {
    for (int i = 0; i < vertices; i++) {
        color[i] = -1;
    }
}

void color_graph(int v, int c) {
    color[v] = c;
    for (int u = 0; u < vertices; u++) {
        if (graph[v][u] == 1 && color[u] == -1) {
            color_graph(u, c + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    init_graph();
    printf("Enter the edges:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    init_colors();
    printf("Enter the number of colors: ");
    scanf("%d", &colors);
    printf("The graph coloring is:\n");
    for (int c = 0; c < colors; c++) {
        for (int v = 0; v < vertices; v++) {
            if (color[v] == -1) {
                color_graph(v, c);
            }
        }
    }
    print_graph();
    return 0;
}