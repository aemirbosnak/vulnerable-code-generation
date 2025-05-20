//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999

// Function prototypes
void printSolution(int color[], int V);
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V);
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V);
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = { {0, 1, 1, 1},
                                                {1, 0, 1, 0},
                                                {1, 1, 0, 1},
                                                {1, 0, 1, 0} };
    
    int m; // Number of colors
    int V = 4; // Number of vertices

    printf("Welcome to the Exciting Graph Coloring Adventure!\n");
    printf("How many colors would you like to use (minimum 1)? ");
    scanf("%d", &m);

    if (m < 1) {
        printf("Come on! You need at least 1 color!\n");
        return 0;
    }

    if (graphColoring(graph, m, V)) {
        printf("Yay! We found a solution with %d colors!\n", m);
    } else {
        printf("Oh no! No solution exists with %d colors.\n", m);
    }
    
    return 0;
}

bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false; // Not safe as adjacent vertex has the same color!
        }
    }
    return true; // It's safe to color!
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) {
    // Base case: If all vertices are processed
    if (v == V) {
        printSolution(color, V);
        return true; // Found a solution!
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c; // Assign color c to vertex v
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true; // Recur to assign colors to rest
            }
            color[v] = 0; // Backtrack if not successful!
        }
    }
    return false; // No solution found for this configuration
}

bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES] = {0}; // Initialize all colors to 0

    // Start from the first vertex
    return graphColoringUtil(graph, m, color, 0, V);
}

void printSolution(int color[], int V) {
    printf("Solution Found: \n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
}