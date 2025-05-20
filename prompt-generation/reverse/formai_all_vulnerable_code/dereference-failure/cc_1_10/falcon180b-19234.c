//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAX_V 1000
#define MAX_E 10000
#define MAX_C 1000

int V, E, C;
int *graph_edges;
int *graph_colors;
int **adj_matrix;

void initialize(int v, int e) {
    V = v;
    E = e;
    C = 0;
    graph_edges = (int*) malloc(E * sizeof(int));
    graph_colors = (int*) malloc(V * sizeof(int));
    adj_matrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj_matrix[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            adj_matrix[i][j] = -1;
        }
    }
}

void add_edge(int u, int v) {
    graph_edges[C] = u;
    graph_edges[C+1] = v;
    C += 2;
}

void read_graph(int v, int e) {
    printf("Enter the edges of the graph:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
}

void print_solution(int v) {
    printf("Color assignment:\n");
    for (int i = 0; i < v; i++) {
        printf("%d ", graph_colors[i]);
    }
    printf("\n");
}

void color_graph(int v, int e) {
    int *queue = (int*) malloc(V * sizeof(int));
    int front = 0, rear = 0;
    int *color_set = (int*) malloc(MAX_C * sizeof(int));
    int num_colors = 0;
    int *color_map = (int*) malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        color_map[i] = -1;
    }
    for (int i = 0; i < v; i++) {
        queue[rear++] = i;
        color_map[i] = num_colors++;
    }
    while (front < rear) {
        int u = queue[front++];
        int *adj_list = adj_matrix[u];
        for (int i = 0; i < V; i++) {
            if (adj_list[i]!= -1 && color_map[i] == -1) {
                queue[rear++] = i;
                color_map[i] = num_colors++;
            }
        }
    }
    printf("Minimum number of colors: %d\n", num_colors);
    for (int i = 0; i < v; i++) {
        graph_colors[i] = color_map[i];
    }
    free(queue);
    free(color_set);
    free(color_map);
}

int main() {
    int v, e;
    printf("Enter the number of vertices and edges in the graph:\n");
    scanf("%d %d", &v, &e);
    initialize(v, e);
    read_graph(v, e);
    color_graph(v, e);
    print_solution(v);
    return 0;
}