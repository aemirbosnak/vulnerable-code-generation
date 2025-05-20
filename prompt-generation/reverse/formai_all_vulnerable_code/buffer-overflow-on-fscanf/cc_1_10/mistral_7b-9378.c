//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100
#define MAX_M 10000
#define MIN_COLOR 1
#define MAX_COLOR 10

typedef struct {
    int adj[MAX_N][MAX_N];
    int n;
} graph_t;

void print_graph(const graph_t *g) {
    for (int i = 0; i < g->n; ++i) {
        printf("%2d: ", i);
        for (int j = 0; j < g->n; ++j) {
            printf("%2d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void graph_read(graph_t *g, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d\n", &g->n);

    for (int i = 0; i < g->n; ++i) {
        for (int j = 0; j < g->n; ++j) {
            fscanf(fp, "%d", &g->adj[i][j]);
        }
    }

    fclose(fp);
}

int graph_color(const graph_t *g, int *color) {
    int num_colors = MIN_COLOR;

    for (int i = 0; i < g->n; ++i) {
        int current_color = color[i];
        if (current_color == -1) {
            current_color = MIN_COLOR;
            color[i] = current_color;
        }

        for (int j = 0; j < g->n; ++j) {
            if (g->adj[i][j] != 0 && color[j] != -1 && abs(color[i] - color[j]) == 1) {
                ++num_colors;
                break;
            }
        }
    }

    return num_colors;
}

int main() {
    srand(time(NULL));

    graph_t g;
    int *color = calloc(g.n, sizeof(int));

    if (color == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for colors\n");
        exit(EXIT_FAILURE);
    }

    graph_read(&g, "sample.txt");

    printf("Input graph:\n");
    print_graph(&g);

    int num_colors = graph_color(&g, color);

    printf("Minimum number of colors: %d\n", num_colors);

    free(color);

    return EXIT_SUCCESS;
}