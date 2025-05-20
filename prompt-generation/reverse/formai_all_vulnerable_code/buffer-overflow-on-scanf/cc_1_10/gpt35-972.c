//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_COLORS 4

int vertices;
int edges;
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init_graph() {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = i + 1; j < vertices; j++) {
            adj_matrix[i][j] = 0;
            adj_matrix[j][i] = 0;
        }
    }
}

void add_edge(int v1, int v2) {
    adj_matrix[v1][v2] = 1;
    adj_matrix[v2][v1] = 1;
}

int is_safe(int vertex, int c) {
    int i;
    for (i = 0; i < vertices; i++) {
        if (adj_matrix[vertex][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex) {
    int c;
    if (vertex == vertices) {
        return 1;
    }
    for (c = 1; c <= MAX_COLORS; c++) {
        if (is_safe(vertex, c)) {
            color[vertex] = c;
            if (graph_coloring(vertex + 1)) {
                return 1;
            }
            color[vertex] = 0;
        }
    }
    return 0;
}

void print_colors() {
    int i;
    printf("\nVertex\tColor\n");
    for (i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    printf("Surprise! We are going to solve the graph coloring problem today!\n\n");
    printf("Please first input the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid input for number of vertices. Program will now exit.\n");
        return 0;
    }
    init_graph();
    printf("\nNow please input the number of edges: ");
    scanf("%d", &edges);
    if (edges < 0 || edges > (vertices * (vertices - 1) / 2)) {
        printf("Invalid input for number of edges. Program will now exit.\n");
        return 0;
    }
    int i, v1, v2;
    printf("\nGreat! Now please input the edges in the format v1 v2 (no commas or brackets needed):\n");
    for (i = 0; i < edges; i++) {
        printf("Edge #%d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices || v1 == v2) {
            printf("Invalid input for an edge. Program will now exit.\n");
            return 0;
        }
        add_edge(v1, v2);
    }
    printf("\nLet's start coloring...\n");
    if (graph_coloring(0)) {
        printf("\nColoring successful! Here are the colors assigned to each vertex:\n");
        print_colors();
    } else {
        printf("\nColoring failed! Sorry, we could not find a solution.\n");
    }
    return 0;
}