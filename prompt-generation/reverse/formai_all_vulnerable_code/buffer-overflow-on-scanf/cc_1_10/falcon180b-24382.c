//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int num_vertices;
int **adj_matrix;
int colors[MAX_VERTICES];

void init_graph(int num_vertices) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_vertices; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
    adj_matrix = (int **) malloc(num_vertices * sizeof(int *));
    for (i = 0; i < num_vertices; i++) {
        adj_matrix[i] = (int *) malloc(num_vertices * sizeof(int));
        for (j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = rand() % 2;
        }
    }
}

void print_graph(int num_vertices) {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("Vertex %d ", j);
            }
        }
    }
}

void color_graph(int num_vertices) {
    int i, j, k, min_color;
    for (i = 0; i < num_vertices; i++) {
        min_color = colors[i];
        for (j = i + 1; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1) {
                for (k = 0; k < MAX_COLORS; k++) {
                    if (colors[j] == k && k < min_color) {
                        min_color = k;
                        break;
                    }
                }
            }
        }
        colors[i] = min_color;
    }
}

int main(int argc, char *argv[]) {
    int num_vertices;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num_vertices);
    init_graph(num_vertices);
    print_graph(num_vertices);
    color_graph(num_vertices);
    printf("\nColored graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, colors[i]);
    }
    return 0;
}