//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int ncolors;
int *color;

void init_graph(int nvertices) {
    int i, j;

    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int is_valid_color(int color, int vertex, int *colors) {
    int i;

    for (i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }

    return 1;
}

int color_graph(int nvertices, int *colors) {
    int i, j, k, l, m, n;
    int count = 0;

    for (i = 0; i < nvertices; i++) {
        colors[i] = 0;
    }

    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            if (graph[i][j] == 1) {
                for (k = 0; k < ncolors; k++) {
                    if (is_valid_color(k, i, colors)) {
                        colors[i] = k;
                        break;
                    }
                }
            }
        }
        count++;
    }

    return count;
}

int main() {
    int i, j;
    int nvertices;
    int ncolors;
    int *colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &nvertices);

    init_graph(nvertices);

    printf("Enter the number of colors: ");
    scanf("%d", &ncolors);

    color = (int *) malloc(nvertices * sizeof(int));

    srand(time(0));

    int max_colors = color_graph(nvertices, color);

    printf("The maximum number of colors is: %d\n", max_colors);

    for (i = 0; i < nvertices; i++) {
        printf("Vertex %d is colored with %d\n", i, color[i]);
    }

    free(color);

    return 0;
}