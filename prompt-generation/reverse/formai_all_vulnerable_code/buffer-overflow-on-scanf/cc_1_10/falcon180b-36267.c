//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 10
#define MAX_COLOR 6

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];
int n;

void print_solution(int n) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int is_valid(int v, int c, int color[], int n) {
    // Check if the color of the adjacent vertex is the same as the current vertex
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int c, int color[], int n) {
    color[v] = c;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            color_graph(i, c, color, n);
        }
    }
}

void backtrack(int v, int c, int color[], int n) {
    if (v == n) {
        print_solution(n);
        exit(0);
    }
    for (int i = 1; i <= MAX_COLOR; i++) {
        if (is_valid(v, i, color, n)) {
            color[v] = i;
            color_graph(v, i, color, n);
        }
    }
    backtrack(v + 1, 0, color, n);
}

int main() {
    srand(time(0));
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    backtrack(0, 0, color, n);
    return 0;
}