//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int vertex;
    struct edge *next;
} edge;

typedef struct {
    int color;
    int visited;
    edge *adj_list;
} vertex;

vertex graph[MAX_VERTICES];
int num_vertices, num_edges;

void add_edge(int src, int dest) {
    edge *new_edge = (edge *) malloc(sizeof(edge));
    new_edge->vertex = dest;
    new_edge->next = graph[src].adj_list;
    graph[src].adj_list = new_edge;

    edge *new_edge2 = (edge *) malloc(sizeof(edge));
    new_edge2->vertex = src;
    new_edge2->next = graph[dest].adj_list;
    graph[dest].adj_list = new_edge2;
}

void initialize_graph() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph[i].color = -1;
        graph[i].visited = 0;
        graph[i].adj_list = NULL;
    }
}

int is_valid_color(int vertex, int color) {
    edge *current = graph[vertex].adj_list;
    while (current != NULL) {
        if (graph[current->vertex].color == color) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int graph_coloring(int vertex, int remaining_colors) {
    if (vertex >= num_vertices) {
        return 1; // all vertices have been colored
    }

    int i;
    for (i = 1; i <= remaining_colors; i++) {
        if (is_valid_color(vertex, i)) {
            graph[vertex].color = i;
            if (graph_coloring(vertex + 1, remaining_colors - 1)) {
                return 1;
            } else {
                graph[vertex].color = -1;
            }
        }
    }

    return 0; // no valid color found for this vertex
}

int main() {
    int i, j, edges;

    scanf("%d %d", &num_vertices, &num_edges);

    initialize_graph();

    for (i = 0; i < num_edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(src, dest);
        add_edge(dest, src);
    }

    if (graph_coloring(0, num_vertices - 1)) {
        for (i = 0; i < num_vertices; i++) {
            printf("%d %d\n", i, graph[i].color);
        }
    } else {
        printf("Graph cannot be colored with given number of colors.\n");
    }

    return 0;
}