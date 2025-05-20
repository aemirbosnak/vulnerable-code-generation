//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 2000

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    int id;
    int degree;
    int *adjacent;
} Vertex;

int num_vertices, num_edges;
int *adj_list;

Vertex *graph;

void init() {
    num_vertices = 0;
    num_edges = 0;
    adj_list = (int *)malloc(MAX_EDGE * sizeof(int));
    graph = (Vertex *)malloc(MAX_VERTEX * sizeof(Vertex));
}

void add_vertex() {
    Vertex v;
    v.id = num_vertices;
    v.degree = 0;
    v.adjacent = (int *)malloc(MAX_EDGE * sizeof(int));
    graph[num_vertices] = v;
    num_vertices++;
}

void add_edge(int u, int v, int w) {
    Edge e;
    e.vertex = v;
    e.weight = w;
    adj_list[num_edges] = v;
    graph[u].adjacent[graph[u].degree++] = num_edges;
    num_edges++;
}

void surreal_graph() {
    init();
    int surreal_num_vertices = rand() % MAX_VERTEX + 1;
    int surreal_num_edges = rand() % MAX_EDGE + 1;
    for (int i = 0; i < surreal_num_vertices; i++) {
        add_vertex();
    }
    for (int i = 0; i < surreal_num_edges; i++) {
        int u = rand() % surreal_num_vertices;
        int v = rand() % surreal_num_vertices;
        int w = rand() % surreal_num_vertices + 1;
        add_edge(u, v, w);
    }
    surreal_num_vertices = surreal_num_vertices - 1;
    surreal_num_edges = surreal_num_edges - 1;
    printf("Surreal Graph:\n");
    printf("Number of vertices: %d\n", surreal_num_vertices);
    printf("Number of edges: %d\n", surreal_num_edges);
}

int main() {
    surreal_graph();
    return 0;
}