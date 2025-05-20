//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int n, m;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int result[MAX_VERTICES];

void init_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("(%d,%d) ", i, j);
            }
        }
    }
}

void color_graph() {
    int k = 0;
    for (int i = 0; i < n; i++) {
        color[i] = k % MAX_COLORS;
        k++;
    }
}

int is_safe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v, int c) {
    if (v == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= MAX_COLORS; i++) {
            if (is_safe(v, i)) {
                color[v] = i;
                result[v] = i;
                backtrack(v + 1, i);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the number of vertices and edges:\n");
    scanf("%d%d", &n, &m);

    init_graph();

    printf("Enter the edges (u,v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    color_graph();

    printf("The initial coloring is:\n");
    print_graph();

    backtrack(0, 1);

    return 0;
}