//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int num_vertices;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void color_graph() {
    int colors_used = 0;
    int vertex = 0;

    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        color[i] = rand() % MAX_COLORS;
        colors_used |= (1 << color[i]);
    }

    while (colors_used!= (1 << MAX_COLORS) - 1) {
        vertex = rand() % num_vertices;

        int color_used = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (graph[vertex][j] == 1 && color[j]!= 0) {
                color_used |= (1 << color[j]);
            }
        }

        int new_color = 0;
        while ((new_color = rand() % MAX_COLORS) == 0 || color_used & (1 << new_color)) {}

        color[vertex] = new_color;
        colors_used |= (1 << new_color);
        colors_used &= ~(1 << color[vertex]);
    }
}

int main() {
    init_graph();

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    color_graph();

    printf("Colored graph:\n");
    print_graph();

    return 0;
}