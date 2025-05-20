//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

int degree[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
int edges[MAX_EDGES][2];
int num_vertices, num_edges, num_colors = 3;

void get_inputs() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges as pairs of vertices (between 0 and %d):\n", num_vertices-1);
    for (int i = 0; i < num_edges; i++) {
        scanf("%d%d", &edges[i][0], &edges[i][1]);
    }
}

void create_graph() {
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
        degree[u]++, degree[v]++;
    }
}

int is_valid(int v, int c) {
    for (int i = 0; i < v; i++) {
        if (graph[v][i] && c == degree[i]) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int *colors) {
    if (v == num_vertices) {
        /* Base case: all vertices have been colored */
        printf("The coloring of the vertices is:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("%d ", colors[i]);
        }
        exit(0);
    }

    /* Try to assign each possible color to vertex v */
    for (int c = 1; c <= num_colors; c++) {
        if (is_valid(v, c)) {
            colors[v] = c;
            color_graph(v+1, colors);
            colors[v] = 0; /* Backtrack */
        }
    }
}

int main() {
    printf("Welcome to the Graph Coloring Problem!\n");
    printf("In this post-apocalyptic world, you have to color the vertices of a graph.\n");
    printf("You can choose any color from {1, 2, 3} to color the vertices.\n");

    get_inputs();
    create_graph();

    int colors[MAX_VERTICES] = {0}; /* Initialize all colors to 0 (unassigned) */
    color_graph(0, colors);

    printf("Sorry, it is not possible to color the vertices of this graph with %d colors.\n", num_colors);
    return 0;
}