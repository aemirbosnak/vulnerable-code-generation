//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_COLOR 7

int graph[MAX_NODES][MAX_NODES];
int n;
int m;
int colors[MAX_NODES];
int color_count;

void init_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void print_colors() {
    printf("Colors:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
}

void color_graph() {
    int start_time = clock();
    int i = 0;
    while (i < MAX_COLOR) {
        int k = 0;
        while (k < n) {
            if (colors[k] == 0) {
                colors[k] = i;
                k++;
            }
        }
        i++;
    }
    int end_time = clock();
    printf("Coloring time: %d\n", end_time - start_time);
}

int main() {
    int i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init_graph();

    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    print_graph();

    color_graph();

    print_colors();

    return 0;
}