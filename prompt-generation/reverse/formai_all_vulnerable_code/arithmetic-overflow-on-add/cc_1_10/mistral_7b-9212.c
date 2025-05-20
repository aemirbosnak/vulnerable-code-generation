//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int vertex1, vertex2;
    int color;
} Edge;

Edge edges[MAX_EDGES];
int num_vertices, num_edges, max_color;
int color_assigned[MAX_VERTICES];

int is_safe(int vertex, int color) {
    for (int i = 0; i < num_edges; i++) {
        if (edges[i].vertex1 == vertex || edges[i].vertex2 == vertex) {
            if (edges[i].color == color) {
                return 0;
            }
        }
    }
    return 1;
}

int graph_coloring() {
    int vertex_to_color;
    for (int color = 1; color <= max_color; color++) {
        vertex_to_color = -1;
        for (int i = 0; i < num_vertices; i++) {
            if (color_assigned[i] == -1) {
                if (is_safe(i, color)) {
                    color_assigned[i] = color;
                    vertex_to_color = i;
                    break;
                }
            }
        }
        if (vertex_to_color == -1) {
            max_color++;
            break;
        }
    }
    return max_color;
}

int main() {
    int num_test_cases, test_case;
    scanf("%d", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++) {
        scanf("%d %d", &num_vertices, &num_edges);
        for (int j = 0; j < num_edges; j++) {
            scanf("%d %d %d", &edges[j].vertex1, &edges[j].vertex2, &edges[j].color);
        }
        max_color = 0;
        for (int k = 0; k < num_vertices; k++) {
            color_assigned[k] = -1;
        }
        graph_coloring();
        printf("Test case %d: Maximum number of colors = %d\n", test_case + 1, max_color);
        test_case++;
    }
    return 0;
}