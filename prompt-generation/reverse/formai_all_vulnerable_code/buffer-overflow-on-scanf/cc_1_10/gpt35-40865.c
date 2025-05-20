//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000
#define MAX_M 10000

int n, m, k;    // n = number of vertices, m = number of edges, k = number of colors
int E[MAX_M][2]; // graph edges
int col[MAX_N];  // vertex colors

// Recursive graph coloring function
bool colorGraph(int v) {
    if (v == n) return true; // All vertices have been colored

    // Try all possible colors for vertex v
    for (int i = 1; i <= k; i++) {
        bool valid = true;

        // Check if color i is valid for vertex v
        for (int j = 0; j < m; j++) {
            if (E[j][0] == v && col[E[j][1]] == i) {
                valid = false;
                break;
            }
            if (E[j][1] == v && col[E[j][0]] == i) {
                valid = false;
                break;
            }
        }

        if (valid) {    // Color i is valid for vertex v
            col[v] = i;

            if (colorGraph(v+1)) return true; // Recursively color remaining vertices

            col[v] = 0; // Backtrack
        }
    }

    return false; // No valid coloring exists
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &E[i][0], &E[i][1]);
    }

    if (colorGraph(0)) {
        printf("Valid coloring exists:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d colored with color %d\n", i+1, col[i]);
        }
    } else {
        printf("No valid coloring exists\n");
    }

    return 0;
}