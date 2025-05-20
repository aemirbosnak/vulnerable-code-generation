//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7

int graph[MAX_NODES][MAX_NODES];
int n_nodes, n_colors;
int *colors;

void init_graph() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void generate_graph() {
    int i, j, k;
    for (i = 0; i < n_nodes; i++) {
        for (j = i + 1; j < n_nodes; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < n_nodes; i++) {
        for (j = 0; j < n_nodes; j++) {
            if (graph[i][j]) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
}

int is_valid_color(int node, int color) {
    int i;
    for (i = 0; i < n_nodes; i++) {
        if (graph[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node, int color) {
    colors[node] = color;
}

void backtrack(int node, int last_color) {
    if (node == n_nodes) {
        printf("Solution found!\n");
        return;
    }
    int i;
    for (i = last_color + 1; i <= n_colors; i++) {
        if (is_valid_color(node, i)) {
            color_node(node, i);
            backtrack(node + 1, i);
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n_nodes);
    printf("Enter the number of colors: ");
    scanf("%d", &n_colors);
    n_nodes = n_nodes < MAX_NODES? n_nodes : MAX_NODES;
    n_colors = n_colors < MAX_COLORS? n_colors : MAX_COLORS;
    colors = (int *)malloc(n_nodes * sizeof(int));
    init_graph();
    generate_graph();
    backtrack(0, 0);
    return 0;
}