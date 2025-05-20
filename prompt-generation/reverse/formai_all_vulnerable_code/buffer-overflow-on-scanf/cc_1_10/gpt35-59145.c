//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 20

typedef struct {
    int n_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

int colors[MAX_VERTICES]; // stores the color assigned to each vertex
int n_colors; // number of colors used

void initialize_colors() {
    int i;
    for(i = 0; i < MAX_VERTICES; i++) {
        colors[i] = -1; // initialize colors to -1 to indicate no color assigned
    }
    n_colors = 0;
}

int is_safe(Graph* g, int vertex, int color) {
    int i;
    for(i = 0; i < g->n_vertices; i++) {
        if(g->adjacency_matrix[vertex][i] == 1 && colors[i] == color) { // if adjacent vertex with the assigned color, return false
            return 0;
        }
    }
    return 1;
}

void backtrack(Graph* g, int vertex) {
    int color;
    if(vertex >= g->n_vertices) { // if all vertices have been assigned a color, print solution and return
        printf("Solution: ");
        int i;
        for(i = 0; i < g->n_vertices; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
        return;
    }
    for(color = 0; color < n_colors; color++) { // try assigning all possible colors
        if(is_safe(g, vertex, color)) { // if safe, assign the color and recursively backtrack to the next vertex
            colors[vertex] = color;
            backtrack(g, vertex+1);
            colors[vertex] = -1;
        }
    }
}

void graph_coloring(Graph* g) {
    initialize_colors();
    int i;
    for(i = 0; i < MAX_COLORS; i++) { // try assigning colors until one is found where no two adjacent vertices have the same color
        n_colors = i+1;
        backtrack(g, 0);
        if(n_colors == i+1) {
            break;
        }
    }
}

int main() {
    Graph g;
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &g.n_vertices);
    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < g.n_vertices; i++) {
        for(j = 0; j < g.n_vertices; j++) {
            scanf("%d", &g.adjacency_matrix[i][j]);
        }
    }
    printf("\n");
    graph_coloring(&g);
    return 0;
}