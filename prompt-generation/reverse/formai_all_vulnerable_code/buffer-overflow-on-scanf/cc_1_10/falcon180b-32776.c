//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} Node;

int num_nodes;
int num_colors;
int **graph;
int *color_map;

bool is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && color_map[i] == color) {
            return false;
        }
    }
    return true;
}

void backtrack(int node, int color) {
    if (node == num_nodes) {
        for (int i = 0; i < num_nodes; i++) {
            printf("%d ", color_map[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= num_colors; i++) {
        if (is_valid_color(node, i)) {
            color_map[node] = i;
            backtrack(node + 1, i);
        }
    }
}

void color_graph(int node, int color) {
    if (node == num_nodes) {
        backtrack(0, 0);
    } else {
        for (int i = 1; i <= num_colors; i++) {
            if (is_valid_color(node, i)) {
                color_map[node] = i;
                color_graph(node + 1, i);
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    graph = (int **)malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        graph[i] = (int *)malloc(num_nodes * sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            graph[i][j] = 0;
        }
    }

    color_map = (int *)malloc(num_nodes * sizeof(int));

    printf("Enter the graph connections (1 for connection, 0 for no connection):\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    color_graph(0, 0);

    return 0;
}