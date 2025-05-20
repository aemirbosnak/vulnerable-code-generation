//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES] = { {0} };
int color[MAX_VERTICES] = { 0 };
int num_colors = 0;
int num_vertices = 0;

void read_graph() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the edges (u v): ");
    while (scanf("%d %d", &i, &j) == 2) {
        graph[i][j] = graph[j][i] = 1;
    }
}

void read_colors() {
    int i;
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    for (i = 0; i < num_colors; i++) {
        color[i] = rand() % MAX_COLORS;
    }
}

int is_valid_color(int v, int c) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j, c;
    srand(time(NULL));

    for (i = 0; i < num_vertices; i++) {
        color[i] = rand() % MAX_COLORS;
    }

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_colors; j++) {
            if (is_valid_color(i, j)) {
                color[i] = j;
                break;
            }
        }
    }

    printf("The coloring is:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("%d -> %d\n", i, color[i]);
    }
}

int main() {
    read_graph();
    read_colors();
    color_graph();

    return 0;
}