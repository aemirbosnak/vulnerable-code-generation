//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

int num_vertices, num_edges;
int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void read_graph() {
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter edges in the format (u v):\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
}

bool is_safe(int u, int colors[], int color) {
    for (int v = 0; v < num_vertices; v++) {
        if (adj_matrix[u][v] && colors[v] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int colors[], int u, int num_colors) {
    if (u == num_vertices) {
        return true;
    }

    for (int i = 1; i <= num_colors; i++) {
        if (is_safe(u, colors, i)) {
            colors[u] = i;
            if (graph_coloring_util(colors, u+1, num_colors)) {
                return true;
            }
            colors[u] = 0;
        }
    }

    return false;
}

bool graph_coloring(int num_colors) {
    int colors[MAX_VERTICES] = {0};

    if (!graph_coloring_util(colors, 0, num_colors)) {
        return false;
    }

    printf("The vertices can be colored with %d colors as follows:\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    return true;
}

int main() {
    read_graph();

    int num_colors;
    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    if (!graph_coloring(num_colors)) {
        printf("Graph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}