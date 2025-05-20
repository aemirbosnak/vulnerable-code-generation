//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if the given coloring is valid
int is_valid_coloring(int *colors, int n, int m, int **graph) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] && colors[i] == colors[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to generate a random coloring
int *random_coloring(int n, int m) {
    int *colors = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = rand() % m + 1;
    }
    return colors;
}

// Function to find the minimum number of colors needed to color the graph
int min_colors(int n, int m, int **graph) {
    int min = m;
    for (int i = 1; i <= m; i++) {
        int *colors = random_coloring(n, i);
        if (is_valid_coloring(colors, n, i, graph)) {
            min = i;
            break;
        }
        free(colors);
    }
    return min;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of nodes and edges
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Create the adjacency matrix
    int **graph = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Get the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the endpoints of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    // Find the minimum number of colors needed to color the graph
    int min = min_colors(n, m, graph);

    // Print the result
    printf("The minimum number of colors needed to color the graph is: %d\n", min);

    // Free the memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}