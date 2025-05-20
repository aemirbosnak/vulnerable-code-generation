//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTEX 10000
#define MAX_COLOR 10000

// Function to print the graph
void printGraph(int V, int graph[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the graph can be colored with the given number of colors
int canColor(int V, int graph[V][V], int colors[], int vertex, int color) {
    int i;
    for (i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    colors[vertex] = color;
    return 1;
}

// Function to color the graph using backtracking
void colorGraph(int V, int graph[V][V], int colors[]) {
    int i, j, k;
    int color = 1;

    for (i = 0; i < V; i++) {
        if (colors[i] == 0) {
            if (!canColor(V, graph, colors, i, color)) {
                color++;
            }
            colors[i] = color;
            color++;
        }
    }
}

// Function to generate a random graph
void generateGraph(int V, int graph[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int main() {
    int V, E, i, j, k;
    int graph[MAX_VERTEX][MAX_VERTEX];
    int colors[MAX_VERTEX];
    int start_time, end_time;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    srand(time(NULL));
    generateGraph(V, graph);

    start_time = clock();
    colorGraph(V, graph, colors);
    end_time = clock();

    printf("\nThe colored graph is:\n");
    printGraph(V, graph);

    printf("\nThe number of colors used is: %d\n", colors[V - 1]);
    printf("The time taken to color the graph is: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}