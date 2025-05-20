//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int num_vertices, num_colors;
int **graph;
int *color;

void init_graph(void) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    graph = (int **)malloc(num_vertices * sizeof(int *));
    for (i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    color = (int *)malloc(num_vertices * sizeof(int));
    for (i = 0; i < num_vertices; i++) {
        color[i] = -1;
    }
}

void print_graph(void) {
    int i, j;

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
}

int is_safe(int v, int c, int *color) {
    int i;

    for (i = 0; i < num_vertices; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }

    return 1;
}

void color_graph(void) {
    int i, j, k;

    srand(time(NULL));
    for (i = 0; i < num_vertices; i++) {
        color[i] = rand() % num_colors;
    }

    printf("Initial coloring:\n");
    print_graph();

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_colors; j++) {
            if (is_safe(i, j, color)) {
                color[i] = j;
                break;
            }
        }
    }

    printf("Final coloring:\n");
    print_graph();
}

int main(void) {
    init_graph();
    color_graph();

    return 0;
}