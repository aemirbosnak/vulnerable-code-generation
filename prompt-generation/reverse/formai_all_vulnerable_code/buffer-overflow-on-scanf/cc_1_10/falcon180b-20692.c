//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTICES; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
}

void print_solution() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }
}

int is_valid(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v) {
    if (v == n - 1) {
        print_solution();
        return;
    }

    for (int c = 1; c <= MAX_COLORS; c++) {
        if (is_valid(v, c)) {
            colors[v] = c;
            backtrack(v + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    init();
    backtrack(0);

    return 0;
}