//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int colors[MAX_COLORS];

void init_graph(int n) {
    nvertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int dfs(int v, int color) {
    int result = 1;
    if (colors[color] == -1) {
        colors[color] = v;
        for (int u = 0; u < nvertices; u++) {
            if (graph[v][u] == 1 && colors[color+1] == -1) {
                result = result && dfs(u, color+1);
            } else if (graph[v][u] == 1 && colors[color+1]!= -1 && colors[color+1]!= u) {
                result = 0;
            }
        }
    } else if (colors[color]!= v) {
        result = 0;
    }
    return result;
}

int backtrack(int v, int color) {
    if (colors[color] == -1) {
        colors[color] = v;
        for (int u = 0; u < nvertices; u++) {
            if (graph[v][u] == 1 && colors[color+1] == -1) {
                if (!backtrack(u, color+1)) {
                    return 0;
                }
            } else if (graph[v][u] == 1 && colors[color+1]!= -1 && colors[color+1]!= u) {
                return 0;
            }
        }
    } else if (colors[color]!= v) {
        return 0;
    }
    return 1;
}

int color_graph() {
    int result = 1;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (colors[i] == -1) {
            result = result && dfs(0, i);
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            add_edge(i, j);
        }
    }
    if (color_graph()) {
        printf("Graph can be colored with %d colors\n", MAX_COLORS);
    } else {
        printf("Graph cannot be colored with %d colors\n", MAX_COLORS);
    }
    for (int i = 0; i < n; i++) {
        if (colors[i]!= -1) {
            printf("%d is colored %d\n", i, colors[i]);
        }
    }
    return 0;
}