//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define NUM_COLORS 4

typedef struct {
    int index;
    int color;
    bool visited;
} Vertex;

int num_vertices;
Vertex *graph;
int *color_map;

void init_graph(void) {
    num_vertices = 0;
    graph = (Vertex *)malloc(MAX_VERTICES * sizeof(Vertex));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i].index = -1;
        graph[i].color = -1;
        graph[i].visited = false;
    }
}

void add_vertex(int index) {
    num_vertices++;
    graph[num_vertices - 1].index = index;
    graph[num_vertices - 1].color = -1;
    graph[num_vertices - 1].visited = false;
}

void add_edge(int v1, int v2) {
    graph[v1].color = -1;
    graph[v2].color = -1;
}

bool dfs(int v, int color) {
    graph[v].color = color;
    graph[v].visited = true;
    for (int i = 0; i < num_vertices; i++) {
        if (!graph[i].visited && graph[v].color == graph[i].color) {
            return false;
        }
    }
    return true;
}

int color_graph(void) {
    int colors_used = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (!graph[i].visited) {
            colors_used = 0;
            for (int j = 0; j < NUM_COLORS; j++) {
                if (dfs(i, j)) {
                    colors_used++;
                    break;
                }
            }
            if (colors_used == 0) {
                return 0;
            }
        }
    }
    return colors_used;
}

int main(void) {
    init_graph();
    add_vertex(0);
    add_vertex(1);
    add_vertex(2);
    add_vertex(3);
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 0);
    int num_colors = color_graph();
    printf("Graph coloring requires %d colors.\n", num_colors);
    return 0;
}