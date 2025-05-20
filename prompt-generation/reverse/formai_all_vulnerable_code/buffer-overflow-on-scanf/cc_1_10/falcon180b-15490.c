//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_COLORS 6
#define MAX_ITERATIONS 100

int n, m;
int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int iterations = 0;

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void read_graph(int n) {
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

void print_solution() {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int color_graph() {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            for (int j = 0; j < MAX_COLORS; j++) {
                if (is_valid(i, j)) {
                    colors[i] = j;
                    k++;
                    break;
                }
            }
        }
    }
    return k;
}

int is_valid(int node, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    init();
    read_graph(n);
    int max_iterations = MAX_ITERATIONS;
    while (iterations < max_iterations) {
        iterations++;
        int k = color_graph();
        if (k == n) {
            print_solution();
            break;
        }
    }
    return 0;
}