//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000
#define MAX_M 10000
#define MAX_C 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, m, c, *graph, **color, *visited;

void init(void) {
    srand(time(NULL));
    n = rand() % MAX_N + 1;
    m = rand() % MAX_M + 1;
    c = rand() % MAX_C + 1;
    graph = (int*)malloc(m * sizeof(int));
    color = (int**)malloc(n * sizeof(int*));
    visited = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color[i] = (int*)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            color[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        graph[i] = rand() % n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            color[i][j] = WHITE;
        }
        visited[i] = WHITE;
    }
}

void print_solution(void) {
    printf("Graph Coloring Solution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", color[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int v, int c) {
    int count = 0;
    for (int i = 0; i < c; i++) {
        if (color[v][i] == c) {
            count++;
        }
    }
    return count == 0;
}

void backtrack(int v, int c) {
    if (v == n) {
        print_solution();
        exit(0);
    }
    for (int i = 0; i < c; i++) {
        if (is_valid(v, i)) {
            color[v][c] = i;
            visited[v] = GRAY;
            backtrack(v + 1, c);
        }
    }
    visited[v] = WHITE;
}

int main(void) {
    init();
    backtrack(0, 0);
    return 0;
}