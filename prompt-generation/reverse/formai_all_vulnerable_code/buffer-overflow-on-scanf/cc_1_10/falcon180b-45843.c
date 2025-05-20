//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 7

int n, m;
int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int num_colors;

void init() {
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

void color_graph() {
    int start_time = clock();
    num_colors = rand() % (MAX_COLORS - 2) + 2;
    printf("Using %d colors\n", num_colors);
    for (int i = 0; i < n; i++) {
        color[i] = rand() % num_colors;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                if (color[i] == color[j]) {
                    printf("Conflict at edge (%d, %d)\n", i, j);
                    exit(1);
                }
            }
        }
    }
    int end_time = clock();
    printf("Coloring completed in %d ms\n", end_time - start_time);
}

int main() {
    init();
    color_graph();
    return 0;
}