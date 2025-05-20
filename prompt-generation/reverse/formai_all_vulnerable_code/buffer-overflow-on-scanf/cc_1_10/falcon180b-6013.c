//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m;
int colors[MAX_VERTICES];
int num_colors;

void init_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges: ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

void init_colors() {
    num_colors = rand() % MAX_COLORS + 1;
    for (int i = 0; i < n; i++) {
        colors[i] = rand() % num_colors;
    }
}

void print_colors() {
    printf("Colors: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int is_valid_color(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int start_time = clock();
    int i;
    for (i = 0; i < n; i++) {
        int c = rand() % num_colors;
        while (!is_valid_color(i, c)) {
            c = rand() % num_colors;
        }
        colors[i] = c;
    }
    int end_time = clock();
    printf("Coloring time: %d\n", end_time - start_time);
}

int main() {
    srand(time(NULL));
    init_graph();
    init_colors();
    color_graph();
    print_colors();
    return 0;
}