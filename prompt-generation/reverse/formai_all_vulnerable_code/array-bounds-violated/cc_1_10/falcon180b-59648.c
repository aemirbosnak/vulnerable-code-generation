//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 6

int graph[MAX_NODES][MAX_NODES];
int n, m;
int colors[MAX_NODES];
int num_colors;

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

void print_solution() {
    int i;
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", colors[i] + 1);
    }
    printf("\n");
}

int is_valid(int node, int color) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int node, int color) {
    if (node == n) {
        num_colors = color;
        return;
    }
    int i;
    for (i = 1; i <= num_colors; i++) {
        if (is_valid(node, i)) {
            colors[node] = i;
            backtrack(node + 1, i);
        }
    }
}

int main() {
    int i, j;
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    init_colors();
    int a, b;
    printf("Enter the edges (in the form of node1 node2):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    backtrack(0, 0);
    print_solution();
    return 0;
}