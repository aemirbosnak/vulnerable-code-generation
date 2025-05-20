//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 6

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n, m;

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int color_graph(int vertex) {
    int i, j;
    for (i = 0; i < vertex; i++) {
        colors[i] = -1;
    }
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            if (graph[i][j] == 1 && colors[i]!= -1 && colors[j] == -1) {
                colors[j] = colors[i];
            }
        }
    }
    for (i = 0; i < vertex; i++) {
        if (colors[i] == -1) {
            colors[i] = 0;
            for (j = 0; j < vertex; j++) {
                if (graph[i][j] == 1 && colors[j]!= 0) {
                    colors[i] = colors[j] + 1;
                    break;
                }
            }
        }
    }
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < vertex; j++) {
            if (graph[i][j] == 1 && colors[i]!= colors[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j, k, sum = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &k, &j);
        add_edge(k, j);
    }
    if (color_graph(n)) {
        for (i = 0; i < n; i++) {
            sum += colors[i];
        }
        printf("The chromatic number of the graph is %d\n", sum);
    } else {
        printf("The graph cannot be colored using 6 colors.\n");
    }
    return 0;
}