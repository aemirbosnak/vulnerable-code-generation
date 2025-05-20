//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_COLORS 4

int graph[MAX_NODES][MAX_NODES];
int node_color[MAX_NODES];

/* Function to check if it is safe to color a node with a given color */
int is_valid_color(int node, int color, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && node_color[i] == color)
            return 0; // color already used by adjacent node
    }
    return 1;
}

/* Recursive function to solve the graph coloring problem */
int graph_color(int n, int m, int node) {
    // base case
    if (node == n) {
        // all nodes are colored
        return 1;
    }

    // try all possible colors for a node
    for (int color = 1; color <= m; color++) {
        if (is_valid_color(node, color, n)) {
            // color node with valid color
            node_color[node] = color;
            // recursively color the remaining nodes
            if (graph_color(n, m, node + 1))
                return 1;
            // backtrack if current color choice does not work
            node_color[node] = 0;
        }
    }

    // no valid color found
    return 0;
}

/* Function to print the solution */
void print_solution(int n) {
    printf("Node colors: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", node_color[i]);
    }
    printf("\n");
}

int main() {
    int n, m; // number of nodes and colors
    printf("Enter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &n);
    printf("Enter the number of colors (max %d): ", MAX_COLORS);
    scanf("%d", &m);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // initialize node colors to 0 (no color)
    for (int i = 0; i < n; i++) {
        node_color[i] = 0;
    }
    // solve graph coloring problem
    if (graph_color(n, m, 0)) {
        printf("Solution found!\n");
        print_solution(n);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}