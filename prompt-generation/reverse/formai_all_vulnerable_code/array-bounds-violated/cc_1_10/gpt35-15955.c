//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int adj_matrix[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int num_nodes, num_edges;

void read_input() {
    int node1, node2;
    scanf("%d %d", &num_nodes, &num_edges);
    for (int i=0; i<num_edges; i++) {
        scanf("%d %d", &node1, &node2);
        adj_matrix[node1][node2] = adj_matrix[node2][node1] = 1;
    }
}

int is_color_valid(int node, int color) {
    for (int i=0; i<num_nodes; i++) {
        if (adj_matrix[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node) {
    for (int color=1; color<=MAX_COLORS; color++) {
        if (is_color_valid(node, color)) {
            colors[node] = color;
            break;
        }
    }
}

void color_graph() {
    for (int node=0; node<num_nodes; node++) {
        color_node(node);
    }
}

void print_colors() {
    for (int i=0; i<num_nodes; i++) {
        printf("Node %d is colored with %d\n", i, colors[i]);
    }
}

int main() {
    read_input();
    color_graph();
    print_colors();
    return 0;
}