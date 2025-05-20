//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
int vertex_colors[MAX_SIZE];
int num_vertices;

void color_vertex(int vertex, int num_colors) {
    int i, color;
    int used_colors[MAX_SIZE] = {0};

    for(i = 1; i <= num_vertices; i++) {
        if(graph[vertex][i]) {
            used_colors[vertex_colors[i]] = 1;
        }
    }

    for(color = 1; color <= num_colors; color++) {
        if(!used_colors[color]) {
            vertex_colors[vertex] = color;
            return;
        }
    }
}

int main() {
    int i, j, num_colors = 1;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= num_vertices; i++) {
        for(j = 1; j <= num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 1; i <= num_vertices; i++) {
        color_vertex(i, num_colors);

        if(vertex_colors[i] > num_colors) {
            num_colors = vertex_colors[i];
        }
    }

    printf("The minimum number of colors required is %d\n", num_colors);

    printf("Vertex colors:\n");
    for(i = 1; i <= num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, vertex_colors[i]);
    }

    return 0;
}