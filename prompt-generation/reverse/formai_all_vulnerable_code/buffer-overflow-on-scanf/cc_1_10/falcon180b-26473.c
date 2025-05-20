//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];

void init_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int vertex) {
    for (int i = 0; i < vertex; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
}

int main() {
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    print_graph(n);
    color_graph(n);
    printf("Colored graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    }
    return 0;
}