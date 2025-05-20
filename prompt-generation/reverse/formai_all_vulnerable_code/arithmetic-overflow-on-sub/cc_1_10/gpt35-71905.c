//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// function to check if the current color is safe or not
int isSafe(int v, int n, int graph[MAX][MAX], int color[], int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// function to assign colors recursively to graph vertices
int assignColors(int n, int graph[MAX][MAX], int color[], int v) {
    // base case: all vertices have been assigned a color
    if (v == n) {
        return 1;
    }
    // try different colors for the current vertex
    for (int c = 1; c <= n; c++) {
        // check if color c is safe for vertex v
        if (isSafe(v, n, graph, color, c)) {
            color[v] = c;
            // recur for the next vertex
            if (assignColors(n, graph, color, v + 1)) {
                return 1;
            }
            // backtrack
            color[v] = 0;
        }
    }
    // if no colors can be assigned to the current vertex, return 0
    return 0;
}

int main() {
    int n, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {0};
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    printf("Enter the edges of the graph (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
    }
    int color[MAX] = {0};
    if (assignColors(n, graph, color, 0)) {
        printf("The vertices can be colored with the following colors:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("The vertices cannot be colored.\n");
    }
    return 0;
}