//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int adj_matrix[MAX_NODES][MAX_NODES];
int node_colors[MAX_NODES];
int num_nodes;

bool color_nodes(int node, int num_colors) {
    if (node == num_nodes) {
        return true;
    }

    for (int color = 1; color <= num_colors; color++) {
        bool valid_color = true;
        for (int i = 0; i < node; i++) {
            if (adj_matrix[node][i] && node_colors[i] == color) {
                valid_color = false;
                break;
            }
        }

        if (valid_color) {
            node_colors[node] = color;
            if (color_nodes(node + 1, num_colors)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    printf("\nEnter the adjacency matrix representing the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    int num_colors;
    printf("\nEnter the number of colors to use: ");
    scanf("%d", &num_colors);

    if (color_nodes(0, num_colors)) {
        printf("\nNode Colors:\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: Color %d\n", i+1, node_colors[i]);
        }
    } else {
        printf("\nImpossible to color the graph using %d colors.\n", num_colors);
    }
    
    return 0;
}