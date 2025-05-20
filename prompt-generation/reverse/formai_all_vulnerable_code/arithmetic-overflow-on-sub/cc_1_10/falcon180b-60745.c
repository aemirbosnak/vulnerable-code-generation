//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define MAX_TRIES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];
int num_colors;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void print_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int is_valid_color(int v, int c) {
    int i;
    for (i = 0; i < v; i++) {
        if (colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j, c;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
    num_colors = 0;
    for (c = 0; c < MAX_COLORS; c++) {
        if (count_color(c) == n) {
            num_colors++;
        }
    }
    printf("Number of colors used: %d\n", num_colors);
    for (i = 0; i < n; i++) {
        printf("Vertex %d is colored %d\n", i, colors[i]);
    }
}

int count_color(int c) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (colors[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph();
    printf("Enter the edges of the graph:\n");
    int m;
    scanf("%d", &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    color_graph();
    return 0;
}