//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_COLORS 7

int num_nodes, num_edges;
int adj_matrix[MAX_NODES][MAX_NODES];
int color_map[MAX_NODES];

void init_graph() {
    srand(time(NULL));
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = rand() % 2;
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        color_map[i] = rand() % MAX_COLORS;
    }
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("Edge from node %d to node %d\n", i, j);
            }
        }
    }
}

void color_node(int node, int color) {
    if (color < MAX_COLORS) {
        color_map[node] = color;
    } else {
        printf("Invalid color: %d\n", color);
    }
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i] == 1 && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    for (int i = 0; i < num_nodes; i++) {
        if (color_map[i] == 0) {
            int color = rand() % MAX_COLORS;
            while (!is_valid_color(i, color)) {
                color = rand() % MAX_COLORS;
            }
            color_node(i, color);
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    init_graph();
    print_graph();
    color_graph();

    return 0;
}