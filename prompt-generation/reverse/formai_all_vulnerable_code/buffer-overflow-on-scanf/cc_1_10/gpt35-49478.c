//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;

// Function to check if a particular vertex can be assigned a given color
int isValidColor(int vertex, int color) {
    for(int i = 0; i < num_vertices; i++) {
        if(graph[vertex][i] && colors[i] == color)
            return 0;
    }
    return 1;
}

// Recursive function to solve the graph coloring problem
int solve(int vertex) {
    if(vertex == num_vertices)
        return 1;

    for(int color = 1; color <= num_vertices; color++) {
        if(isValidColor(vertex, color)) {
            colors[vertex] = color;
            if(solve(vertex+1))
                return 1;
            colors[vertex] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if(solve(0) == 0) {
        printf("Graph cannot be colored using %d colors\n", num_vertices);
    }
    else {
        printf("Colors assigned to vertices are:\n");
        for(int i = 0; i < num_vertices; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    }

    return 0;
}