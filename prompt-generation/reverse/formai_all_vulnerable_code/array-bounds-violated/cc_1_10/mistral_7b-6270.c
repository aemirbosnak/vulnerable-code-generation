//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6
typedef struct {
    int vertex;
    int color;
} Graph[MAX_VERTICES];
void print_graph(Graph g, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d : %d\n", g[i].vertex, g[i].color);
        for (j = 0; j < n; j++) {
            if (g[i].vertex == g[j].vertex || (g[i].color == g[j].color && i != j)) {
                printf("\t%d : %d\n", g[j].vertex, g[j].color);
            }
        }
    }
}
bool is_valid_color(Graph g, int n, int vertex, int color) {
    int i;
    for (i = 0; i < n; i++) {
        if (g[i].vertex == vertex || g[i].color == color) {
            return false;
        }
    }
    return true;
}
bool graph_coloring(Graph g, int n, int m) {
    int i, color;
    for (i = 0; i < n; i++) {
        color = MIN_COLOR;
        while (!is_valid_color(g, n, i, color)) {
            color++;
            if (color > MAX_COLOR) {
                return false;
            }
        }
        g[i].color = color;
    }
    return true;
}
int main() {
    int n, m;
    Graph g;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d%d", &n, &m);
    printf("Enter the vertices and edges:\n");
    for (int i = 0; i < n; i++) {
        g[i].vertex = i;
        g[i].color = MIN_COLOR;
    }
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        if (g[v1].color == g[v2].color) {
            printf("Graph is not colorable.\n");
            return 1;
        }
    }
    if (graph_coloring(g, n, m)) {
        printf("Graph colored successfully.\n");
        print_graph(g, n);
    }
    return 0;
}