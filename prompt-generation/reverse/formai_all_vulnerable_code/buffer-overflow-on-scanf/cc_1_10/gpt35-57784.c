//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];
int num_vertex;

void ReadInput() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertex);

    printf("Enter the adjacency matrix for the graph: \n");
    for (int i = 0; i < num_vertex; i++) {
        for (int j = 0; j < num_vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int IsValidColor(int vertex, int c) {
    for (int i = 0; i < num_vertex; i++) {
        if (graph[vertex][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int GraphColoring(int vertex) {
    if (vertex == num_vertex)
        return 1;

    for (int c = 1; c <= num_vertex; c++) {
        if (IsValidColor(vertex, c)) {
            color[vertex] = c;
            if (GraphColoring(vertex + 1) == 1)
                return 1;
            color[vertex] = 0;
        }
    }
    return 0;
}

void PrintSolution() {
    printf("\nGraph coloring solution:\n");
    for (int i = 0; i < num_vertex; i++) {
        printf("Vertex %d: Colored with %d\n", i, color[i]);
    }
}

int main() {
    printf("Welcome to the Graph Coloring Problem Solver!\n\n");
    ReadInput();

    if (GraphColoring(0) == 1) {
        PrintSolution();
    } 
    else {
        printf("No possible coloring of the graph with %d colors.\n", num_vertex);
    }

    return 0;
}