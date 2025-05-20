//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

/* This struct represents a vertex in a graph */
struct vertex {
    int color; /* The color assigned to this vertex */
    int degree; /* The degree of this vertex */
    int adjacency[MAX_VERTICES]; /* The adjacency list */
};

/* This struct represents a graph */
struct graph {
    int num_vertices; /* The number of vertices in this graph */
    struct vertex vertices[MAX_VERTICES]; /* The vertices in this graph */
};

/* This function assigns a color to a vertex in a graph */
void color_vertex(struct graph *g, int v) {
    int i, j, adj_color;
    int color_options[] = {1, 2, 3, 4, 5}; /* The possible colors to choose from */

    /* Check the colors of adjacent vertices */
    for (i = 0; i < g->num_vertices; i++) {
        if (g->vertices[i].adjacency[v] == 1 && g->vertices[i].color != 0) {
            /* If an adjacent vertex is already colored, remove that color from the options */
            for (j = 0; j < 5; j++) {
                if (color_options[j] == g->vertices[i].color) {
                    color_options[j] = 0;
                }
            }
        }
    }

    /* Choose the smallest available color for this vertex */
    for (i = 0; i < 5; i++) {
        if (color_options[i] != 0) {
            g->vertices[v].color = color_options[i];
            break;
        }
    }
}

/* This function colors a graph using a greedy algorithm */
void color_graph(struct graph *g) {
    int i, j, max_degree = 0, max_degree_vertex;

    /* Find the vertex with the highest degree */
    for (i = 0; i < g->num_vertices; i++) {
        g->vertices[i].color = 0; /* Initialize all vertices to color 0 */
        if (g->vertices[i].degree > max_degree) {
            max_degree = g->vertices[i].degree;
            max_degree_vertex = i;
        }
    }

    /* Color the vertex with the highest degree */
    g->vertices[max_degree_vertex].color = 1;

    /* Color the remaining vertices */
    for (i = 1; i < g->num_vertices; i++) {
        for (j = 0; j < g->num_vertices; j++) {
            if (g->vertices[j].color == 0) {
                /* If this vertex is uncolored, color it */
                color_vertex(g, j);
            }
        }
    }
}

int main() {
    int i, j, num_vertices, num_edges, v, w;
    struct graph g;

    /* Get the number of vertices and edges */
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    /* Initialize the graph */
    g.num_vertices = num_vertices;
    for (i = 0; i < num_vertices; i++) {
        g.vertices[i].degree = 0;
        for (j = 0; j < num_vertices; j++) {
            g.vertices[i].adjacency[j] = 0;
        }
    }

    /* Get the edges */
    printf("Enter the edges in the graph:\n");
    for (i = 0; i < num_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &v, &w);
        g.vertices[v].adjacency[w] = 1;
        g.vertices[w].adjacency[v] = 1;
        g.vertices[v].degree++;
        g.vertices[w].degree++;
    }

    /* Color the graph using the greedy algorithm */
    color_graph(&g);

    /* Print the vertex colors */
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, g.vertices[i].color);
    }

    return 0;
}