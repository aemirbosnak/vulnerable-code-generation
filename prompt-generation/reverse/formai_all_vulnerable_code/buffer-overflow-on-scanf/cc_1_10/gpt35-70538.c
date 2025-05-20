//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representation of the graph
int colors[MAX_VERTICES]; // array to store the color assigned to each vertex
int num_vertices, num_edges; // number of vertices and edges in the graph

// function to read in the graph from standard input
void readGraph() {
    scanf("%d %d", &num_vertices, &num_edges);
    int u, v;
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // add edge to the graph
    }
}

// function to check if it is safe to assign a color to a vertex
bool isSafe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// function to solve the graph coloring problem using backtracking
bool graphColorUtil(int v) {
    if (v == num_vertices) {
        return true; // all vertices have been assigned a color
    }
    for (int c = 1; c <= MAX_COLORS; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;
            if (graphColorUtil(v + 1)) {
                return true;
            }
            colors[v] = 0; // backtrack and try a different color
        }
    }
    return false; // no color can be assigned to this vertex
}

// function to print the color assigned to each vertex
void printColors() {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main() {
    readGraph();
    if (graphColorUtil(0)) {
        printf("Solution found!\n");
        printColors();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}