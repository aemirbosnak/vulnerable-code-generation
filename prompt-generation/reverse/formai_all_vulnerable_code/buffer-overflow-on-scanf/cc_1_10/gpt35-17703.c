//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000 // maximum number of vertices in the graph

int n; // number of vertices in the graph
int adj[MAX_N][MAX_N]; // adjacency matrix of the graph

int color[MAX_N]; // color of each vertex
bool used[MAX_N]; // whether a color has already been used for this vertex

// function to check if a vertex can be colored with a given color
bool canColor(int u, int c) {
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && color[v] == c) {
            return false;
        }
    }
    return true;
}

// function to assign colors to vertices recursively
bool colorGraphHelper(int u) {
    if (u == n) {
        return true;
    }
    for (int c = 1; c <= n; c++) {
        if (used[c]) {
            continue;
        }
        if (canColor(u, c)) {
            color[u] = c;
            used[c] = true;
            if (colorGraphHelper(u + 1)) {
                return true;
            }
            used[c] = false;
        }
    }
    return false;
}

// function to assign colors to vertices in the graph
bool colorGraph() {
    return colorGraphHelper(0);
}

int main() {
    // read input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // color the graph
    if (colorGraph()) {
        // print the colors
        printf("The vertices can be colored using the following colors:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        // the graph cannot be colored
        printf("The graph cannot be colored.\n");
    }

    return 0;
}