//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100

int graph[MAX_VERTEX][MAX_VERTEX];
int n, m;
int vertex_color[MAX_VERTEX];
int num_colors;

void read_graph(void) {
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void create_color_map(int start_color) {
    int i, j;
    for (i = 0; i < n; i++) {
        vertex_color[i] = start_color;
        start_color++;
    }
}

int is_valid_color(int v, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && vertex_color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int c) {
    vertex_color[v] = c;
    num_colors++;
}

void backtrack(int v, int c) {
    if (v == n) {
        num_colors++;
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && is_valid_color(i, c + 1)) {
            color_graph(i, c + 1);
            backtrack(i, c + 1);
        }
    }
}

int main(void) {
    read_graph();
    create_color_map(1);
    backtrack(0, 1);
    printf("Number of colors used: %d\n", num_colors);

    return 0;
}