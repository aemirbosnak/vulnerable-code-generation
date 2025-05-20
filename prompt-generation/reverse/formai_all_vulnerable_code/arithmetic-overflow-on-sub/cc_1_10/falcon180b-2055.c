//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

// Function to print the graph
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n, int colors[MAX_VERTICES]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given vertex is adjacent to another vertex
int isAdjacent(int graph[MAX_VERTICES][MAX_VERTICES], int i, int j) {
    if (graph[i][j]!= 0) {
        return 1;
    }
    return 0;
}

// Function to find a valid color for a given vertex
int findColor(int colors[MAX_VERTICES], int vertex, int color) {
    while (colors[vertex] == color || isAdjacent(colors, vertex, color)) {
        color++;
        if (color == MAX_COLORS) {
            color = 0;
        }
    }
    return color;
}

// Function to color the graph using the backtracking algorithm
void backtrack(int graph[MAX_VERTICES][MAX_VERTICES], int n, int colors[MAX_VERTICES], int vertex, int color) {
    if (vertex == n - 1) {
        return;
    }
    int nextColor = findColor(colors, vertex, color);
    colors[vertex] = nextColor;
    backtrack(graph, n, colors, vertex + 1, nextColor);
}

// Function to generate a random graph
void generateGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int main() {
    int n, i, j, colors[MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[MAX_VERTICES][MAX_VERTICES];
    generateGraph(graph, n);
    printf("Adjacency matrix:\n");
    printGraph(graph, n, colors);
    printf("\n");
    int start = 0;
    int end = n - 1;
    int color = 0;
    backtrack(graph, n, colors, start, color);
    printf("Colored graph:\n");
    printGraph(graph, n, colors);
    return 0;
}