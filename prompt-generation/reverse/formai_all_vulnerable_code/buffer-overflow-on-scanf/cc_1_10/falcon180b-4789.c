//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n, m;
int color_count;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void init_colors() {
    int i;
    for (i = 0; i < n; i++) {
        colors[i] = -1;
    }
}

int is_valid(int vertex, int color) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        if (colors[i] == -1) {
            color_count++;
            colors[i] = color_count;
            for (j = 0; j < n; j++) {
                if (graph[i][j] == 1 && colors[j] == -1) {
                    colors[j] = colors[i];
                }
            }
        }
    }
}

int main() {
    int i, j, k;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    init_graph();
    init_colors();
    printf("Enter the edges (u v): ");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &k, &j);
        graph[k][j] = 1;
        graph[j][k] = 1;
    }
    color_graph();
    printf("The vertices are colored as follows:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
    return 0;
}