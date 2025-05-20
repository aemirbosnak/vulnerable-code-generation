//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;
int colors[MAX_VERTICES];
int num_colors;

void init_graph() {
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void init_colors() {
    for (int i = 0; i < n; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
    num_colors = 0;
}

int is_valid_color(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v, int c) {
    if (v == n) {
        num_colors++;
        return;
    }
    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_valid_color(v, i)) {
            colors[v] = i;
            backtrack(v + 1, i);
        }
    }
}

void color_graph() {
    init_colors();
    backtrack(0, 0);
    printf("Number of colors: %d\n", num_colors);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    print_graph();
    color_graph();
    return 0;
}