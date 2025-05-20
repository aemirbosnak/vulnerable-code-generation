//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;
int colors[MAX_VERTICES];
int current_color = 0;
int color_count = 0;

void init() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        colors[i] = -1;
    }
}

void dfs(int v) {
    colors[v] = current_color;
    color_count++;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == -1) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init();

    printf("Enter the edges: ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            current_color++;
            dfs(i);
        }
    }

    printf("The minimum number of colors is: %d\n", current_color);

    return 0;
}