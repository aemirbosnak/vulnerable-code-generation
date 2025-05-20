//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10000
#define MAX_COLORS 7

int num_nodes;
int num_colors;
int **graph;
int *node_color;

void init() {
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_colors = rand() % MAX_COLORS + 1;
    graph = (int **)malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        graph[i] = (int *)malloc(num_nodes * sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            graph[i][j] = rand() % 2;
        }
    }
    node_color = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        node_color[i] = -1;
    }
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && node_color[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node, int color) {
    node_color[node] = color;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && node_color[i] == -1) {
            color_node(i, color);
        }
    }
}

int main() {
    init();
    int start_time = clock();
    color_node(0, 0);
    int end_time = clock();
    printf("Time taken: %d ms\n", end_time - start_time);
    return 0;
}