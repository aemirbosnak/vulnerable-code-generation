//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n;
int m;
int i;
int j;
int k;
int start_vertex;
int end_vertex;
int color_count;
int color_array[MAX_COLORS];

void initialize_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge() {
    printf("Enter the start vertex: ");
    scanf("%d", &start_vertex);
    printf("Enter the end vertex: ");
    scanf("%d", &end_vertex);
    graph[start_vertex][end_vertex] = 1;
    graph[end_vertex][start_vertex] = 1;
}

void read_graph() {
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        add_edge();
    }
}

int is_connected(int v, int c) {
    color[v] = c;
    color_array[c] = 1;
    color_count++;
    for (k = 0; k < n; k++) {
        if (graph[v][k] == 1) {
            if (color[k] == -1) {
                if (color_count >= MAX_COLORS) {
                    return 0;
                }
                color[k] = c;
                color_array[c] = 1;
                color_count++;
            } else if (color[k]!= c) {
                return 0;
            }
        }
    }
    return 1;
}

int backtrack(int v, int c) {
    if (v == -1) {
        return 1;
    }
    for (k = 0; k < n; k++) {
        if (graph[v][k] == 1 && color[k] == -1) {
            if (backtrack(k, c)) {
                color[k] = c;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    initialize_graph();
    read_graph();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n) {
        j = 0;
        while (j < n) {
            if (color[j] == -1) {
                if (is_connected(i, j)) {
                    i++;
                }
            }
            j++;
        }
        k++;
    }
    printf("The chromatic number of the graph is %d\n", k);
    return 0;
}