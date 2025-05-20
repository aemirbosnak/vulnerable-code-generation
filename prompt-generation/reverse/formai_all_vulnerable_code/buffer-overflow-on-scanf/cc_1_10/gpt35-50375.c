//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100 // maximum number of vertices

int graph[MAX_N][MAX_N]; // adjacency matrix representation 
int color[MAX_N]; // to store the color assigned to each vertex
int n; // number of vertices

// function to check if a given color can be assigned to a vertex
bool is_valid_color(int v, int c)
{
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// function to solve the graph coloring problem using backtracking
bool graph_coloring(int v)
{
    if (v == n) // all vertices have been assigned a color
        return true;

    // try all possible colors for vertex v
    for (int c = 1; c <= n; c++) {
        if (is_valid_color(v, c)) {
            color[v] = c;
            if (graph_coloring(v+1)) // recurse for next vertex
                return true;
            color[v] = 0; // backtrack if solution not possible
        }
    }
    return false; // no valid color found for vertex v
}

// function to print the solution
void print_solution()
{
    printf("Vertex colors are:\n");
    for (int i = 0; i < n; i++)
        printf("Vertex %d: Color %d\n", i+1, color[i]);
}

int main()
{
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    // initialize graph with all zeros
    memset(graph, 0, sizeof(graph));

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (graph_coloring(0)) {
        print_solution();
    } else {
        printf("No valid coloring possible!\n");
    }

    return 0;
}