//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

void printSolution(int color[]) {
    printf("Graph colored successfully with the following colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
    }
    printf("Thank you for using the Graph Coloring Program!\n");
}

bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        printSolution(color);
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            if (graphColorUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all colors to 0
    }

    if (!graphColorUtil(graph, m, color, 0)) {
        printf("No solution exists for coloring the graph with %d colors. Thank you for trying!\n", m);
        return false;
    }
    return true;
}

int main() {
    int m; // Number of colors
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };

    printf("Welcome to the Graph Coloring Program!\n");
    printf("Please enter the number of colors you wish to use: ");
    scanf("%d", &m);

    printf("Your graph is represented as follows:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    if (graphColoring(graph, m)) {
        printf("Graph coloring completed. Thank you for using our program!\n");
    } else {
        printf("There was an issue with the graph coloring. We appreciate your input!\n");
    }

    return 0;
}