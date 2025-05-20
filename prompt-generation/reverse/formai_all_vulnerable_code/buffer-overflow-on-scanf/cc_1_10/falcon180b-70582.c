//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

// Graph representation as an adjacency matrix
int graph[MAX_NODES][MAX_NODES];

// Number of nodes and colors
int n, m;

// Solution matrix - stores the color assigned to each node
int solution[MAX_NODES];

// Function to initialize the graph with random edges
void initialize_graph() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                graph[i][j] = rand() % m;
            } else {
                graph[i][j] = 0;
            }
        }
    }
}

// Function to print the graph as an adjacency matrix
void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given node can be assigned a given color
int is_valid(int node, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == color || graph[i][node] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to color the graph using backtracking
void color_graph() {
    for (int i = 0; i < n; i++) {
        solution[i] = -1;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (solution[i] == -1) {
            int color = k % m;
            while (!is_valid(i, color)) {
                color = (color + 1) % m;
            }
            solution[i] = color;
            k++;
        }
    }
}

// Function to print the solution matrix
void print_solution() {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    initialize_graph();
    print_graph();
    color_graph();
    print_solution();
    return 0;
}