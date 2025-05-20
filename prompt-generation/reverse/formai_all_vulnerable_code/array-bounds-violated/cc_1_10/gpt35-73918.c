//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include<stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];

int coloring[MAX_VERTICES];

int is_valid_color(int vertex, int color, int num_vertices) {
    for(int i=0; i<num_vertices; i++) {
        if(graph[vertex][i] && color==coloring[i]) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring(int vertex, int num_vertices, int num_colors) {
    if(vertex==num_vertices) {
        printf("\nColoring found: ");
        for(int i=0; i<num_vertices; i++) {
            printf("%d ", coloring[i]);
        }
        return;
    }
    for(int i=1; i<=num_colors; i++) {
        if(is_valid_color(vertex, i, num_vertices)) {
            coloring[vertex] = i;
            graph_coloring(vertex+1, num_vertices, num_colors);
            coloring[vertex] = 0;
        }
    }
    return;
}

int main() {
    int num_vertices, num_edges;
    printf("\nEnter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("\nEnter number of edges: ");
    scanf("%d", &num_edges);
    printf("\nEnter edges: ");
    for(int i=0; i<num_edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    int num_colors;
    printf("\nEnter number of colors: ");
    scanf("%d", &num_colors);
    graph_coloring(0, num_vertices, num_colors);
    printf("\n");
    return 0;
}