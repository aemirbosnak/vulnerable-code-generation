//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 101
#define MAX_M 10001

typedef struct {
    int x, y;
} Edge;

bool graph[MAX_N][MAX_N];
int color[MAX_N];
int n, m;
Edge edges[MAX_M];
int num_colors = 1;

bool is_valid_color(int v, int c) {
    for (int u = 1; u <= n; u++) {
        if (graph[u][v] && color[u] == c) {
            return false;
        }
    }
    return true;
}

void print_result() {
    for (int i = 1; i <= n; i++) {
        printf("%d: %d\n", i, color[i]);
    }
}

void read_input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = true;
        graph[v][u] = true;
        edges[i].x = u;
        edges[i].y = v;
    }
}

void init_colors() {
    for (int i = 1; i <= n; i++) {
        color[i] = 0;
    }
}

bool try_color(int v, int c) {
    if (!is_valid_color(v, c)) {
        return false;
    }
    color[v] = c;
    for (int i = 0; i < m; i++) {
        int u = edges[i].x;
        if (u != v && !try_color(u, c % num_colors)) {
            color[v] = 0;
            return false;
        }
    }
    return true;
}

bool graph_coloring() {
    for (int v = 1; v <= n; v++) {
        if (!try_color(v, 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    read_input();
    init_colors();
    if (graph_coloring()) {
        print_result();
    } else {
        printf("Graph cannot be colored.\n");
    }
    return 0;
}