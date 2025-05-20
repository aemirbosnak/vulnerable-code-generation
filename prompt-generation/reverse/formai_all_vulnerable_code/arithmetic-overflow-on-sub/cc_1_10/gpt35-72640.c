//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXV 15         // Maximum number of vertices
#define MAXCOLORS 5     // Maximum number of colors

int adj[MAXV][MAXV];    // Adjacency matrix
int colors[MAXV];       // Color of each vertex
int n, m;               // Number of vertices and edges

// Check if a vertex can be colored with a given color
int canColor(int v, int color) {
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Assign colors to vertices using backtracking
int colorVertices(int v) {
    if (v == n) {
        return 1;   // All vertices have been colored
    }
    for (int i = 1; i <= MAXCOLORS; i++) {
        if (canColor(v, i)) {
            colors[v] = i;                  // Assign color i to vertex v
            if (colorVertices(v + 1)) {     // Color the next vertex
                return 1;
            }
            colors[v] = 0;         // Unassign color i from vertex v
        }
    }
    return 0;   // No color can be assigned to vertex v
}

// Generate a random graph
void generateGraph() {
    srand(time(NULL));
    m = rand() % ((n * (n - 1)) / 2 + 1);    // Random number of edges
    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        while (u == v || adj[u][v]) {   // Check if edge already exists
            u = rand() % n;
            v = rand() % n;
        }
        adj[u][v] = adj[v][u] = 1;      // Add edge
    }
}

// Print the graph
void printGraph() {
    printf("Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// Print the colors of the vertices
void printColors() {
    printf("Colors:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of vertices (max %d): ", MAXV);
    scanf("%d", &n);
    if (n > MAXV) {
        printf("Error: Too many vertices\n");
        exit(EXIT_FAILURE);
    }
    generateGraph();
    printGraph();
    if (colorVertices(0)) {
        printColors();
    } else {
        printf("Error: Graph not colorable\n");
    }
    return 0;
}