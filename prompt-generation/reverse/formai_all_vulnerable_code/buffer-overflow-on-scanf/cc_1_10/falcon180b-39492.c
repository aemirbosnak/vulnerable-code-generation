//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 7

int num_vertices;
int **adj_matrix;
int *color;
int *parent;

void init(int v) {
    num_vertices = v;
    adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i] = (int *)malloc((num_vertices - 1) * sizeof(int));
    }
    color = (int *)malloc(num_vertices * sizeof(int));
    parent = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        color[i] = -1;
        parent[i] = -1;
    }
}

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

int find_parent(int v) {
    if (parent[v] == -1) {
        return v;
    }
    return find_parent(parent[v]);
}

void merge_parents(int u, int v) {
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);
    if (parent_u!= parent_v) {
        if (color[parent_u] < 0) {
            color[parent_u] = color[parent_v];
        } else if (color[parent_v] < 0) {
            color[parent_v] = color[parent_u];
        }
        parent[parent_v] = parent_u;
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    init(v);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        color[i] = rand() % MAX_COLORS;
    }
    for (int i = 0; i < num_vertices; i++) {
        if (color[i] < 0) {
            color[i] = rand() % MAX_COLORS;
        }
    }
    int num_colors = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (color[i] >= 0) {
            num_colors++;
        }
    }
    printf("Minimum number of colors: %d\n", num_colors);
    return 0;
}