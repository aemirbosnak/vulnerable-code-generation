//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9
#define N 3

int graph[V][V];
int n;
int m;
int **result;
int **color;
bool isSafe(int v, int c, int **color, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (color[v][i] == c || color[i][v] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoring(int v, int **color, int n) {
    if (v == n) {
        return true;
    }
    int c = 1;
    while (c <= n) {
        if (isSafe(v, c, color, n)) {
            color[v][0] = c;
            for (int i = 1; i < n; i++) {
                color[v][i] = 0;
            }
            if (graphColoring(v + 1, color, n)) {
                return true;
            }
        }
        c++;
    }
    return false;
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges and their weights:\n");
    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int **result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    int **color = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        color[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            color[i][j] = 0;
        }
    }
    if (graphColoring(0, color, n)) {
        printf("The minimum number of colors required is: %d\n", n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = color[i][j];
            }
        }
        printf("The graph coloring is:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", n);
    }
    for (i = 0; i < n; i++) {
        free(color[i]);
    }
    free(color);
    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}