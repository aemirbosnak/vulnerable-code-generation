//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define MAX_COLOR 10

typedef struct {
    int color;
    int next;
} Vertex;

Vertex vertices[MAX_VERTEX];
int num_vertices, num_colors;

void add_vertex(int color, int next) {
    vertices[num_vertices].color = color;
    vertices[num_vertices].next = next;
    num_vertices++;
}

void color_graph(int vertex) {
    if (vertex == num_vertices) {
        return;
    }

    int color = 0;
    for (int i = 1; i <= num_colors; i++) {
        if (vertices[i].color == 0) {
            color = i;
            break;
        }
    }

    vertices[vertex].color = color;

    color_graph(vertices[vertex].next);
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d -> %d\n", vertices[i].color, vertices[i].next);
    }
}

int main() {
    int num_vertices = 0, num_colors = 0;
    int vertex, color;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    for (int i = 0; i < num_vertices; i++) {
        printf("Enter vertex %d color: ", i + 1);
        scanf("%d", &color);
        add_vertex(color, i);
    }

    color_graph(0);
    print_graph();

    printf("Minimum number of colors used: %d\n", num_colors);

    return 0;
}