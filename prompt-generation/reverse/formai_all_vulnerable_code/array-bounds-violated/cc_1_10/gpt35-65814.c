//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int G[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int color[MAX_VERTICES];

void color_graph(int vertex, int num_vertices, int num_colors) {
    if(vertex == num_vertices) {
        printf("\nSolution:\n");
        for(int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
        return;
    }

    for(int i = 1; i <= num_colors; i++) {
        int valid_color = 1;
        for(int j = 0; j < num_vertices; j++) {
            if(G[vertex][j] && color[j] == i) {
                valid_color = 0;
                break;
            }
        }
        if(valid_color) {
            color[vertex] = i;
            color_graph(vertex + 1, num_vertices, num_colors);
            color[vertex] = 0;
        }
    }
}

int main() {
    int num_vertices, num_edges, num_colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the edges: \n");
    for(int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }

    for(int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
        color[i] = 0;
    }

    color_graph(0, num_vertices, num_colors);

    return 0;
}