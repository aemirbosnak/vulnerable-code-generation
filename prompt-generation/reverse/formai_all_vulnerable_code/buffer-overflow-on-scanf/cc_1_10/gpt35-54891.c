//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define RED 1
#define GREEN 2
#define BLUE 3

typedef struct Edge {
    int u, v;
} Edge;

int n, m; // number of vertices and edges
Edge edges[MAX_EDGES + 1];
int colors[MAX_VERTICES + 1];

void read_graph() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Enter the edges (u, v):\n");
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }
}

int can_color(int vertex, int color) {
    for (int i = 1; i <= m; ++i) {
        if (edges[i].u == vertex && colors[edges[i].v] == color) {
            return 0;
        }
        if (edges[i].v == vertex && colors[edges[i].u] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    for (int i = 1; i <= n; ++i) {
        colors[i] = RED;
    }
    for (int i = 1; i <= n; ++i) {
        if (can_color(i, GREEN)) {
            colors[i] = GREEN;
        } else if (can_color(i, BLUE)) {
            colors[i] = BLUE;
        }
    }
}

void print_colors() {
    printf("Colors:\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    read_graph();
    color_graph();
    print_colors();
    return 0;
}