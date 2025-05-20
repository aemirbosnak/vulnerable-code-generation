//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the graph
void printGraph(int graph[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the coloring is valid
int isValid(int graph[10][10], int n, int color[10], int v) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[v] == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to color the graph
int colorGraph(int graph[10][10], int n, int color[10]) {
    int v = 0;
    while (v < n) {
        int c = 1;
        while (c <= n) {
            if (isValid(graph, n, color, v)) {
                color[v] = c;
                v++;
                break;
            }
            c++;
        }
    }
    return v;
}

// Function to generate a random graph
void generateGraph(int graph[10][10], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

// Main function
int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int graph[10][10], color[10];
    generateGraph(graph, n);
    int v = colorGraph(graph, n, color);
    printf("The colored graph is:\n");
    printGraph(graph, n);
    return 0;
}