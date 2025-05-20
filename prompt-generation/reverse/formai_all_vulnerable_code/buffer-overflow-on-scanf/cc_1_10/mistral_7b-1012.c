//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} vertex_t;

typedef struct {
    int start;
    int end;
} edge_t;

vertex_t graph[MAX_VERTICES];
int num_vertices, num_edges;
edge_t edges[MAX_EDGES];

bool is_valid_color(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[i].vertex == vertex && graph[i].color == color) {
            return false;
        }
        if (graph[i].vertex != vertex && abs(graph[i].vertex - vertex) == 1 && graph[i].color == color) {
            return false;
        }
    }
    return true;
}

void print_graph() {
    printf("Current graph state:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d has color %d\n", graph[i].vertex, graph[i].color);
    }
}

void color_graph_greedily() {
    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        int vertex = rand() % num_vertices;
        int color = MIN_COLOR;
        while (!is_valid_color(vertex, color)) {
            color++;
            if (color > MAX_COLOR) {
                color = MIN_COLOR;
            }
        }
        graph[vertex].color = color;
    }
}

void read_input() {
    scanf("%d %d", &num_vertices, &num_edges);
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[i].start, &edges[i].end);
    }
}

int main() {
    read_input();

    for (int i = 0; i < num_vertices; i++) {
        graph[i].vertex = i;
        graph[i].color = -1;
    }

    color_graph_greedily();

    print_graph();

    return 0;
}