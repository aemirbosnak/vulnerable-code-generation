//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLOR 7

typedef struct {
    int vertex;
    int color;
} vertex_t;

bool graph[MAX_VERTICES][MAX_VERTICES];
vertex_t vertices[MAX_VERTICES];
int num_vertices, num_edges;

void initialize_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = false;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = true;
    graph[v][u] = true;
}

int max_color(int v) {
    int max = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (i != v && graph[i][v] && vertices[i].color > max) {
            max = vertices[i].color;
        }
    }
    return max;
}

bool is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[i][v] && vertices[i].color == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int m, int n) {
    int i, c;
    if (m > n) {
        return true;
    }
    initialize_graph();
    for (i = 0; i < n; i++) {
        add_edge(m, i);
    }
    for (i = 0; i < n; i++) {
        vertices[i].vertex = i;
        vertices[i].color = INT_MAX;
    }
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        c = rand() % (m + 1);
        while (!is_safe(i, c)) {
            c = rand() % (m + 1);
        }
        vertices[i].color = c;
    }
    for (i = 0; i < n; i++) {
        if (max_color(i) >= vertices[i].color) {
            return false;
        }
    }
    printf("Graph Coloring with %d colors:\n", m);
    for (i = 0; i < n; i++) {
        printf("Vertex %d with color %d\n", vertices[i].vertex, vertices[i].color);
    }
    return true;
}

int main() {
    int num_tests, i, j, u, v;
    scanf("%d", &num_tests);
    for (i = 0; i < num_tests; i++) {
        scanf("%d%d", &num_vertices, &num_edges);
        for (j = 0; j < num_edges; j++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        graph_coloring(num_vertices - 1, num_vertices);
    }
    return 0;
}