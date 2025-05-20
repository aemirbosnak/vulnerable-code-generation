//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n, m;

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(int v, int c) {
    if (v >= n)
        return true;

    for (int i = MIN_COLOR; i <= m; i++) {
        if (isSafe(v, i)) {
            color[v] = i;
            if (graphColoringUtil(v + 1, i))
                return true;
            color[v] = -1; // backtrack
        }
    }
    return false;
}

bool graphColoring() {
    m = 1;

    while (graphColoringUtil(0, m) == false && m++ < MAX_VERTICES);

    if (m > MAX_VERTICES) {
        printf("Graph cannot be colored with %d colors or less.\n", MAX_VERTICES);
        return false;
    }

    printf("Graph colored with %d colors:\n", m);
    for (int i = 0; i < n; i++)
        printf("Vertex %d colored with %d\n", i, color[i]);

    return true;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges as source target:\n");

    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        graph[s][t] = graph[t][s] = 1;
    }

    graphColoring();

    return 0;
}