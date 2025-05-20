//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 5

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n, m;

void initialize() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
    }
}

void print_graph() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int is_safe(int v, int c, int j) {
    if (graph[v][j] == 1) {
        return 0;
    }
    for (int k = 0; k < n; ++k) {
        if (graph[v][k] == 1 && color[k] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int c) {
    color[v] = c;
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] == 1) {
            if (!is_safe(v, c, i)) {
                printf("Not safe\n");
                exit(0);
            }
        }
    }
}

int main() {
    int i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges:\n");
    for (i = 0; i < m; ++i) {
        scanf("%d %d", &j, &k);
        --j;
        --k;
        graph[j][k] = 1;
        graph[k][j] = 1;
    }
    initialize();
    printf("Initial graph:\n");
    print_graph();
    int count = 0;
    for (i = 0; i < n; ++i) {
        if (color[i] == 0) {
            color_graph(i, count % MAX_COLORS);
            ++count;
        }
    }
    printf("Colored graph:\n");
    print_graph();
    return 0;
}