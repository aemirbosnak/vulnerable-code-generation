//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7

int graph[MAX_NODES][MAX_NODES] = {0};
int n, m;
int colors[MAX_NODES];

void init_graph() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
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
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

void color_graph(int node, int color) {
    colors[node] = color;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == -1) {
            color_graph(i, color + 1);
        } else if (graph[node][i] == 1 && colors[i]!= -1 && colors[i]!= color + 1) {
            printf("Invalid coloring\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    init_graph();
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            int color = rand() % MAX_COLORS;
            color_graph(i, color);
        }
    }
    printf("Coloring:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
    print_graph();
    return 0;
}