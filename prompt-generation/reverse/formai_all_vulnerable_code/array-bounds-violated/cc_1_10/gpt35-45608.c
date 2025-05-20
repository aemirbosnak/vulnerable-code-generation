//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int colors[MAX_VERTICES];

int is_valid_color(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return 0;
        }
    }
    return 1;
}

int graph_color(int vertex) {
    if (vertex == num_vertices) {
        return 1;
    }
    
    for (int i = 0; i < MAX_COLORS; i++) {
        if (is_valid_color(vertex, i)) {
            colors[vertex] = i;
            
            if (graph_color(vertex+1)) {
                return 1;
            }
            
            colors[vertex] = 0;
        }
    }
    
    return 0;
}

int main() {
    int num_edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    
    for (int i = 0; i < num_edges; i++) {
        int v1, v2;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    
    if (graph_color(0)) {
        printf("Graph colored successfully.\n");
        printf("Vertex\tColor\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("%d\t%d\n", i, colors[i]);
        }
    } else {
        printf("Unable to color the graph.\n");
    }
    
    return 0;
}