//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define V 9
#define MAX_COLOR 7

int graph[V][V];
int color[V];
int n;

void init_graph() {
    int i, j;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the vertices and their connections (u v):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void init_colors() {
    int i;
    for (i = 0; i < n; i++) {
        color[i] = 0;
    }
}

int is_safe(int v, int c) {
    int i, j;

    for (i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] && graph[v][i] && color[i] == c && color[j] == c) {
                return 0;
            }
        }
    }

    return 1;
}

void color_graph(int v) {
    int i, c;

    for (c = 1; c <= MAX_COLOR; c++) {
        if (is_safe(v, c)) {
            color[v] = c;
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (graph[v][i]) {
            color[i] = c;
        }
    }
}

void print_solution() {
    int i, j;

    printf("Vertex\tColor\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    init_graph();
    init_colors();

    int i;
    for (i = 0; i < n; i++) {
        color_graph(i);
    }

    print_solution();

    return 0;
}