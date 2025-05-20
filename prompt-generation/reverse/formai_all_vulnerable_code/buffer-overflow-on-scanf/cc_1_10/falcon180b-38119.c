//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10
#define INF 99999

int n, m;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int min_color = 1;

void init_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 100;
        }
    }
}

void init_colors() {
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }
}

int is_valid_color(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i]!= 0 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_vertex(int v, int c) {
    color[v] = c;
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void print_colors() {
    for (int i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    scanf("%d %d", &n, &m);
    init_graph();
    init_colors();
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (is_valid_color(u, min_color)) {
            color_vertex(u, min_color);
            min_color++;
        } else if (is_valid_color(v, min_color)) {
            color_vertex(v, min_color);
            min_color++;
        } else {
            printf("Invalid input\n");
            return 0;
        }
    }
    printf("Graph colored with %d colors:\n", min_color - 1);
    print_graph();
    print_colors();
    return 0;
}