//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 7
#define MAX_ITER 100

int n, m;
int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
bool visited[MAX_NODES];

void init() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % MAX_NODES;
        }
        colors[i] = rand() % MAX_COLORS;
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

bool dfs(int node, int color) {
    visited[node] = true;
    colors[node] = color;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 &&!visited[i]) {
            if (!dfs(i, color)) {
                return false;
            }
        }
    }
    return true;
}

void color_graph() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int color = rand() % MAX_COLORS;
            visited[i] = true;
            colors[i] = color;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 &&!visited[j]) {
                    if (!dfs(j, color)) {
                        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
                        exit(0);
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init();
    print_graph();

    printf("Coloring graph...\n");
    color_graph();

    printf("Colors:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }

    return 0;
}