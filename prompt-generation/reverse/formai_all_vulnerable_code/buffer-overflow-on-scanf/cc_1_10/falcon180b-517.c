//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_colors;

void init_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 2;
            }
        }
    }
}

void print_graph(int num_vertices) {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph(int num_vertices) {
    int i, j, k, min_color;
    for (i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }
    num_colors = 0;
    for (i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            colors[i] = num_colors;
            num_colors++;
            for (j = 0; j < num_vertices; j++) {
                if (graph[i][j] == 1) {
                    for (k = 0; k < num_vertices; k++) {
                        if (colors[k]!= -1 && graph[k][j] == 1) {
                            min_color = colors[k];
                            break;
                        }
                    }
                    colors[i] = min_color;
                }
            }
        }
    }
}

void print_colors(int num_vertices) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    init_graph();
    color_graph(num_vertices);
    printf("Adjacency matrix:\n");
    print_graph(num_vertices);
    printf("Colors:\n");
    print_colors(num_vertices);
    return 0;
}