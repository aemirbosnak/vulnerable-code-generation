//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int nodes, colors;
int graph[MAX_NODES][MAX_NODES];
int colors_used[MAX_COLORS];

int is_safe(int node, int color) {
    for (int i = 0; i < nodes; i++) {
        if (graph[node][i] == 1 && colors_used[color] == 1) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int node) {
    if (node == nodes) {
        return 1;
    }

    for (int color = 1; color <= colors; color++) {
        if (is_safe(node, color)) {
            colors_used[color] = 1;
            if (color_graph(node + 1)) {
                return 1;
            }
            colors_used[color] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (color_graph(0)) {
        printf("Graph can be colored with %d colors:\n", colors);
        for (int i = 0; i < nodes; i++) {
            for (int color = 1; color <= colors; color++) {
                if (colors_used[color] == 1) {
                    printf("Node %d: Color %d\n", i + 1, color);
                }
            }
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", colors);
    }

    return 0;
}