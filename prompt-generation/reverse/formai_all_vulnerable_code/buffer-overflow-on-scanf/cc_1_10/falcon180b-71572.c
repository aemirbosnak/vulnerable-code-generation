//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define INF INT_MAX

int n, m;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int result[MAX_VERTICES];
int min_colors;

void init_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                graph[i][j] = rand() % (MAX_COLORS - 1) + 1;
            } else {
                graph[i][j] = 0;
            }
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph(int v) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i]!= 0 && color[i] == 0) {
            color[i] = (color[v] + 1) % MAX_COLORS;
            result[i] = v;
        }
    }
}

void backtrack(int v) {
    if (v == -1) {
        min_colors = min_colors < n? min_colors : n;
        return;
    }
    color_graph(v);
    int u = result[v];
    backtrack(u);
}

int main() {
    srand(time(NULL));

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    init_graph();
    print_graph();

    backtrack(0);

    printf("Minimum number of colors: %d\n", min_colors);

    return 0;
}