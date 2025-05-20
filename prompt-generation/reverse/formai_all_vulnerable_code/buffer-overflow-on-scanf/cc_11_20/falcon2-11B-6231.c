//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 3

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices = 0;
int num_colors = 0;

int main() {
    int num_edges = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int u, v, c;
        printf("Enter edge %d: ", i + 1);
        scanf("%d%d%d", &u, &v, &c);
        graph[u][v] = c;
    }

    int color_count[MAX_COLORS] = {0};
    for (int i = 0; i < num_vertices; i++) {
        int curr_color = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] == INT_MAX || color_count[graph[i][j]] == 0) {
                colors[i] = curr_color;
                color_count[curr_color]++;
            }
        }
    }

    int num_colors_required = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i]!= num_colors) {
            num_colors_required++;
        }
    }

    if (num_colors_required == num_vertices) {
        printf("No solution exists.\n");
    } else {
        printf("A solution exists with %d colors.\n", num_colors_required);
    }

    return 0;
}