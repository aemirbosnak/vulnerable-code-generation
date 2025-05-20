//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int id;
    int color;
} vertex;

typedef struct {
    int id;
    int num_vertices;
    vertex **adj_list;
} graph;

void *color_vertex(void *arg) {
    int *color = (int *) arg;
    int id = rand() % (*color);
    printf("Vertex %d colored %d\n", id, *color);
    return NULL;
}

graph *create_graph(int num_vertices) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->id = num_vertices;
    g->num_vertices = num_vertices;
    g->adj_list = (vertex **) malloc(num_vertices * sizeof(vertex *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = (vertex *) malloc(sizeof(vertex));
        g->adj_list[i]->id = i;
        g->adj_list[i]->color = -1;
    }
    return g;
}

void add_edge(graph *g, int v1, int v2) {
    g->adj_list[v1]->color = g->adj_list[v2]->color = -2;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d - Color %d\n", g->adj_list[i]->id, g->adj_list[i]->color);
    }
}

void color_graph(graph *g, int num_colors) {
    pthread_t threads[num_colors];
    int colors[num_colors];
    for (int i = 0; i < num_colors; i++) {
        colors[i] = i;
        pthread_create(&threads[i], NULL, color_vertex, &colors[i]);
    }
    for (int i = 0; i < num_colors; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    srand(time(NULL));
    graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);
    add_edge(g, 3, 4);
    add_edge(g, 4, 2);
    printf("Graph before coloring:\n");
    print_graph(g);
    color_graph(g, 3);
    printf("\nGraph after coloring:\n");
    print_graph(g);
    return 0;
}