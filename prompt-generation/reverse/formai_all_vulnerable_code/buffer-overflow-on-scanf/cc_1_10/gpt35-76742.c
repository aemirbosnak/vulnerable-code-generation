//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 26

typedef struct vertex {
    int id;
    int color;
    int *adj_list;
    int adj_count;
} Vertex;

Vertex graph[MAX_VERTICES];
int num_vertices;

int valid_color(Vertex v, int color) {
    int i;
    for (i = 0; i < v.adj_count; i++) {
        int adj_id = v.adj_list[i];
        if (graph[adj_id].color == color) {
            return 0;
        }
    }
    return 1;
}

int graph_color(int vertex_id, int num_colors) {
    if (vertex_id == num_vertices) {
        return 1;
    }

    Vertex *v = &graph[vertex_id];
    int i;
    for (i = 1; i <= num_colors; i++) {
        if (valid_color(*v, i)) {
            v->color = i;
            if (graph_color(vertex_id + 1, num_colors)) {
                return 1;
            }
            v->color = 0;
        }
    }

    return 0;
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    for (i = 0; i < num_vertices; i++) {
        graph[i].id = i;
        graph[i].color = 0;

        int adj_count;
        printf("Enter number of adjacent vertices for vertex %d: ", i);
        scanf("%d", &adj_count);

        graph[i].adj_count = adj_count;
        graph[i].adj_list = malloc(sizeof(int) * adj_count);

        printf("Enter adjacent vertex IDs for vertex %d: ", i);
        for (j = 0; j < adj_count; j++) {
            scanf("%d", &graph[i].adj_list[j]);
        }
    }

    int num_colors = 1;
    while (!graph_color(0, num_colors)) {
        num_colors++;
    }

    printf("The minimum number of colors needed to color the graph is: %d\n", num_colors);

    for (i = 0; i < num_vertices; i++) {
        free(graph[i].adj_list);
    }

    return 0;
}