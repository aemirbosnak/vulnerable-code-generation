//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

// Graph representation using adjacency matrix
int graph[MAX_NODES][MAX_NODES];

// Number of nodes and edges
int n, m;

// Function to initialize the graph
void initializeGraph(int nodes, int edges) {
    n = nodes;
    m = edges;

    // Initialize graph with -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1;
        }
    }

    // Add edges to graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

// Function to print the solution
void printSolution(int solution[], int n) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
}

// Function to check if two colors are conflicting
int isConflicting(int node, int color1, int color2, int solution[], int n) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && solution[i] == color1) {
            return 1;
        }
        if (graph[node][i] == 1 && solution[i] == color2) {
            return 1;
        }
    }
    return 0;
}

// Function to color the graph using backtracking
void colorGraph(int node, int color, int solution[], int n) {
    if (node == n - 1) {
        printSolution(solution, n);
        return;
    }

    // Try all colors from 1 to MAX_COLORS
    for (int i = 1; i <= MAX_COLORS; i++) {
        // Check if the color is conflicting with adjacent nodes
        if (isConflicting(node, color, i, solution, n)) {
            continue;
        }

        // Assign the color to the current node
        solution[node] = i;

        // Recursively color the rest of the graph
        colorGraph(node + 1, i, solution, n);
    }
}

// Main function
int main() {
    int nodes, edges;

    // Read input
    scanf("%d %d", &nodes, &edges);

    // Initialize graph
    initializeGraph(nodes, edges);

    // Color the graph
    int solution[MAX_NODES];
    colorGraph(0, 1, solution, nodes);

    return 0;
}