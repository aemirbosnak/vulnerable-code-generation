//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 6

int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int n;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j]) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

void color_node(int u) {
    int c;
    for (c = 0; c < MAX_COLORS; c++) {
        if (color[u]!= c && color[(u + 1) % n]!= c && color[(u + 2) % n]!= c) {
            color[u] = c;
            return;
        }
    }
}

void color_graph() {
    int i;
    for (i = 0; i < n; i++) {
        color_node(i);
    }
}

void print_colors() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main() {
    int i, j;

    srand(time(NULL));
    printf("Enter the number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &n);

    printf("Initial graph:\n");
    init_graph();
    print_graph();

    printf("Coloring the graph:\n");
    color_graph();
    print_graph();
    print_colors();

    return 0;
}