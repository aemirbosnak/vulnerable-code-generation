//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERTEX_COUNT 10
#define COLOR_COUNT 5

typedef struct {
    int vertex_index;
    int color_index;
} Edge;

Edge edges[VERTEX_COUNT][VERTEX_COUNT];
int color_count[COLOR_COUNT] = {0};

bool is_valid_color(int vertex_index, int color_index) {
    for (int i = 0; i < vertex_index; i++) {
        if (edges[vertex_index][i].color_index == color_index) {
            return false;
        }
    }
    return true;
}

bool color_graph(int vertex_index, int color_index) {
    if (vertex_index == VERTEX_COUNT) {
        return true;
    }

    for (int i = 0; i < VERTEX_COUNT; i++) {
        if (is_valid_color(vertex_index, color_index)) {
            edges[vertex_index][i].color_index = color_index;
            color_count[color_index]++;
            if (color_graph(vertex_index + 1, color_index)) {
                return true;
            }
            color_count[color_index]--;
        }
    }

    return false;
}

int main() {
    int i, j;

    for (i = 0; i < VERTEX_COUNT; i++) {
        for (j = 0; j < VERTEX_COUNT; j++) {
            edges[i][j].vertex_index = j;
        }
    }

    int max_color_count = 0;
    for (i = 0; i < VERTEX_COUNT; i++) {
        for (j = 0; j < VERTEX_COUNT; j++) {
            if (is_valid_color(i, j)) {
                edges[i][j].color_index = j;
                color_count[j]++;
                if (max_color_count < color_count[j]) {
                    max_color_count = color_count[j];
                }
            }
        }
    }

    printf("Max color count: %d\n", max_color_count);

    return 0;
}