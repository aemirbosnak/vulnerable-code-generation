//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>

#define MAX_NODES 100 // Maximum number of nodes in the graph

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix for the graph
int num_nodes; // Number of nodes in the graph

// Return true if node 'n' can be colored with color 'c'
int can_color(int n, int c, int colors[]) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[n][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to color the nodes of the graph
int color_nodes(int n, int colors[]) {
    if (n == num_nodes) { // base case: all nodes have been colored
        return 1;
    }
    for (int c = 1; c <= num_nodes; c++) {
        if (can_color(n, c, colors)) {
            colors[n] = c;
            if (color_nodes(n + 1, colors)) { // try to color the next node
                return 1; // success!
            }
            colors[n] = 0; // backtrack
        }
    }
    return 0; // failure
}

int main() {
    // Read the input graph
    scanf("%d", &num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // Color the nodes of the graph
    int colors[MAX_NODES] = {0};
    if (color_nodes(0, colors)) {
        // Print the colors of the nodes
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: color %d\n", i+1, colors[i]);
        }
    }
    else {
        printf("Sorry, could not color the nodes of the graph.\n");
    }
    return 0;
}