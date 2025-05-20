//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color_map[MAX_VERTICES];
int num_vertices;
int num_colors;

void create_graph(int vertices) {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = (rand() % 2)? 1 : 0;
        }
    }
}

int is_valid_color(int vertex, int color) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j, k;
    for (i = 0; i < num_vertices; i++) {
        color_map[i] = rand() % num_colors;
    }

    while (1) {
        int changed = 0;
        for (i = 0; i < num_vertices; i++) {
            if (color_map[i] == -1) {
                int color = rand() % num_colors;
                while (!is_valid_color(i, color)) {
                    color = (color + 1) % num_colors;
                }
                color_map[i] = color;
                changed = 1;
            }
        }

        if (!changed) {
            break;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j]) {
                printf("%d ", color_map[i]);
            } else {
                printf("-1 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, vertices;

    srand(time(NULL));

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    num_vertices = vertices;
    num_colors = rand() % (vertices / 2) + 2;

    create_graph(vertices);

    color_graph();

    printf("Colored graph:\n");
    print_graph();

    return 0;
}