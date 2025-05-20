//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int num_nodes, num_colors;
int **graph;
int *color_map;

void init_graph(int n) {
    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void init_color_map(int n, int c) {
    color_map = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color_map[i] = -1;
    }
}

int is_valid(int node, int color, int *color_map) {
    if (color_map[node] == -1) {
        return 1;
    }
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int n, int c) {
    int node = 0;
    while (node < n) {
        int color = rand() % c;
        if (is_valid(node, color, color_map)) {
            color_map[node] = color;
            node++;
        }
    }
}

void print_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                printf("%d ", graph[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n, c;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &c);
    init_graph(n);
    init_color_map(n, c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter 1 if %d and %d are connected, 0 otherwise: ", i, j);
            int connected;
            scanf("%d", &connected);
            if (connected) {
                graph[i][j] = 1;
            }
        }
    }
    color_graph(n, c);
    printf("Graph:\n");
    print_graph(n);
    printf("Color map:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", color_map[i]);
    }
    printf("\n");
    return 0;
}