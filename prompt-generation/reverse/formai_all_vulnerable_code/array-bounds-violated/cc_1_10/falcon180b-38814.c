//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 7
#define MAX_ITERATIONS 1000

int num_nodes, num_colors;
int adj_matrix[MAX_NODES][MAX_NODES];
int color_map[MAX_NODES];
int num_colors_used;
int iter;

void initialize_graph() {
    srand(time(NULL));
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = rand() % 2;
        }
    }
}

int is_valid_coloring(int color, int node) {
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i] == 1 && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node, int color) {
    color_map[node] = color;
    num_colors_used++;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    initialize_graph();

    for (int i = 0; i < num_nodes; i++) {
        color_map[i] = -1;
    }

    iter = 0;
    while (iter < MAX_ITERATIONS && num_colors_used < num_colors) {
        int node = rand() % num_nodes;
        int color = rand() % num_colors;
        if (is_valid_coloring(color, node)) {
            color_node(node, color);
            num_colors_used++;
        }
        iter++;
        if (iter % 100 == 0) {
            printf("Iteration %d: %d colors used\n", iter, num_colors_used);
        }
    }

    printf("Final coloring:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d -> %d\n", i, color_map[i]);
    }

    return 0;
}