//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 7

typedef struct {
    int vertex;
    int color;
} Vertex;

Vertex *graph;
int num_vertices;
int num_colors;

void initialize_graph(int n) {
    num_vertices = n;
    graph = (Vertex *)malloc(sizeof(Vertex) * n);
    for (int i = 0; i < n; i++) {
        graph[i].vertex = i;
        graph[i].color = 0;
    }
}

void initialize_colors() {
    num_colors = rand() % MAX_COLORS + 1;
    int *colors = (int *)malloc(sizeof(int) * num_colors);
    for (int i = 0; i < num_colors; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
    for (int i = 0; i < num_vertices; i++) {
        graph[i].color = colors[rand() % num_colors];
    }
    free(colors);
}

int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[i].color == c) {
            if (graph[i].vertex == v || graph[i].vertex == v + 1 || graph[i].vertex == v - 1) {
                return 0;
            }
        }
    }
    return 1;
}

void color_graph(int v, int c) {
    graph[v].color = c;
}

void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d %d\n", graph[i].vertex, graph[i].color);
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initialize_graph(n);
    initialize_colors();
    printf("Initial graph:\n");
    print_graph();
    printf("Colored graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        color_graph(i, rand() % num_colors);
    }
    print_graph();
    return 0;
}