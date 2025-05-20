//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int n, m;
int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int num_colors;

int is_valid_color(int c) {
    for (int i = 0; i < n; i++) {
        if (color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int u, int c) {
    color[u] = c;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && color[v] == -1) {
            if (!is_valid_color(c)) {
                c++;
            }
            dfs(v, c);
        }
    }
}

void color_graph() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    num_colors = 0;
    dfs(0, 0);
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v): ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    color_graph();
    printf("Number of colors used: %d\n", num_colors);
    return 0;
}