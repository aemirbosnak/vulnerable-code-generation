//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 6

int num_vertices;
int **adj_matrix;
int *colors;

void init_graph(int v) {
    num_vertices = v;
    adj_matrix = (int **)malloc(v * sizeof(int *));
    colors = (int *)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        adj_matrix[i] = (int *)malloc(v * sizeof(int));
        colors[i] = -1;
    }
}

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

int is_safe(int v, int c, int *visited) {
    visited[v] = 1;
    for (int u = 0; u < num_vertices; u++) {
        if (adj_matrix[v][u] && colors[u] == c) {
            return 0;
        }
        if (adj_matrix[v][u] && colors[u] == -1) {
            int res = is_safe(u, c, visited);
            if (!res) {
                return 0;
            }
        }
    }
    return 1;
}

int color_graph() {
    int *visited = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
        visited[i] = 0;
    }
    int c = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            if (!is_safe(i, c, visited)) {
                c++;
            }
            colors[i] = c;
        }
    }
    free(visited);
    return c;
}

int main() {
    srand(time(NULL));
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    init_graph(v);
    for (int i = 0; i < e; i++) {
        int u, v;
        printf("Enter two vertices: ");
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int c = color_graph();
    printf("Graph colored with %d colors\n", c);
    return 0;
}