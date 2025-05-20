//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100
#define MAX_COLOR 6

typedef struct {
    int adj[MAX_VERTS][MAX_COLOR];
    int color[MAX_VERTS];
} graph;

void read_graph(graph *g, int num_verts) {
    int i, j, k, vert1, vert2, color;

    for (i = 0; i < num_verts; i++) {
        for (j = 0; j < num_verts; j++) {
            for (k = 0; k < MAX_COLOR; k++) {
                g->adj[i][k] = 0;
            }
        }
        g->color[i] = -1;

        scanf("%d", &vert1);
        scanf("%d", &vert2);

        if (vert1 != -1 && vert2 != -1) {
            scanf("%d", &color);
            g->adj[vert1][color] = 1;
            g->adj[vert2][color] = 1;
        }
    }
}

int is_valid_color(graph *g, int vert, int color) {
    int i;

    for (i = 0; i < MAX_COLOR; i++) {
        if (g->adj[vert][i] && g->color[vert] != i && g->color[i] != color) {
            return 0;
        }
    }

    return 1;
}

int graph_coloring(graph *g, int num_verts) {
    int i, best_color = -1, color;

    for (i = 0; i < num_verts; i++) {
        if (g->color[i] == -1) {
            for (color = 0; color < MAX_COLOR; color++) {
                if (is_valid_color(g, i, color)) {
                    g->color[i] = color;
                    if (i == num_verts - 1) {
                        best_color = color;
                        break;
                    }
                }
            }

            if (g->color[i] == -1) {
                return -1;
            }
        }
    }

    return best_color;
}

void print_graph(graph *g, int num_verts) {
    int i, j, color;

    printf("Coloring:\n");
    for (i = 0; i < num_verts; i++) {
        printf("Vertex %d: Color %d\n", i, g->color[i]);
    }

    printf("Adjacency matrix:\n");
    for (i = 0; i < num_verts; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < MAX_COLOR; j++) {
            if (g->adj[i][j]) {
                printf("Color %d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    graph g;
    int num_verts, best_color;

    scanf("%d", &num_verts);
    read_graph(&g, num_verts);

    best_color = graph_coloring(&g, num_verts);
    if (best_color != -1) {
        print_graph(&g, num_verts);
    } else {
        printf("Graph cannot be colored.\n");
    }

    return 0;
}