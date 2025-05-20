//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

#define MAXVERTICES 50
#define MAXCOLORS 50

int n;  // number of vertices
int e;  // number of edges
int adj[MAXVERTICES][MAXVERTICES];  // adjacency matrix
int colors[MAXVERTICES];  // color assignments

/* function to check if it is safe to color a vertex with a given color */
int isSafe(int vertex, int color, int color_array[]) {
    for(int i = 0; i < n; ++i) {  // iterate over all vertices
        if(adj[vertex][i] && color_array[i] == color) {  // if there is an edge between the vertices and they have the same color
            return 0;
        }
    }
    return 1;
}

/* function to recursively color the graph */
void colorGraph(int vertex, int color_array[]) {
    if(vertex == n) {  // all vertices have been colored
        for(int i = 0; i < n; ++i) {
            printf("%d ", color_array[i]);  // print the color assignments
        }
        printf("\n");
        return;
    }
    for(int c = 1; c <= e; ++c) {  // try all colors
        if(isSafe(vertex, c, color_array)) {  // if it is safe to color the vertex with the current color
            color_array[vertex] = c;  // assign the color to the vertex
            colorGraph(vertex + 1, color_array);  // recursively color the next vertex
            color_array[vertex] = 0;  // undo the color assignment
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &e);

    for(int i = 0; i < e; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    colorGraph(0, colors);
    return 0;
}