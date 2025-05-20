//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 50
#define MAX_COLOR 6

int graph[MAX_VERTICES][MAX_VERTICES];
int n, m, colors[MAX_VERTICES];

bool is_valid(int vertex, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void graph_coloring(int vertex, int remaining_colors) {
    if (vertex >= n) {
        printf("Solution:\n");
        for (int i = 0; i < n; i++) {
            printf("%d: %d\n", i, colors[i]);
        }
        exit(EXIT_SUCCESS);
    }

    for (int color = 1; color <= remaining_colors; color++) {
        if (is_valid(vertex, color)) {
            colors[vertex] = color;
            graph_coloring(vertex + 1, remaining_colors - 1);
            break;
        }
    }

    if (colors[vertex] == 0) {
        graph_coloring(vertex + 1, remaining_colors);
    }
}

int main() {
    srand(time(NULL));

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        colors[i] = -1;
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
            if (graph[i][j]) {
                printf("(%d, %d) is an edge\n", i, j);
            }
        }
    }

    graph_coloring(0, MAX_COLOR);

    return EXIT_SUCCESS;
}