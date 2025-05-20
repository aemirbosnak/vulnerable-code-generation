//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

void initialize_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
}

int is_connected(int v, int color) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] == 1 && colors[i]!= -1 && colors[i]!= color) {
            return 0;
        }
    }
    return 1;
}

int color_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        colors[i] = -1;
    }
    int k = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (colors[i] == -1) {
            colors[i] = k++;
            for (j = 0; j < MAX_VERTICES; j++) {
                if (graph[i][j] == 1 && colors[j] == -1) {
                    colors[j] = k++;
                }
            }
        }
    }
    return k;
}

int main() {
    int i, j, k, n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initialize_graph();
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int num_colors = color_graph();
    printf("The minimum number of colors needed is: %d\n", num_colors);
    return 0;
}