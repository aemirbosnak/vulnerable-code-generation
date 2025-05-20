//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_colors;

void generate_random_graph() {
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = rand() % num_colors;
    }
}

int main() {
    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    num_vertices = num_edges + 1;
    num_colors = num_vertices - 1;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        printf("Enter the two vertices connected by edge %d: ", i+1);
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    generate_random_graph();
    color_graph();

    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < num_colors; j++) {
            if (colors[i] == j) {
                printf("%d ", j);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}