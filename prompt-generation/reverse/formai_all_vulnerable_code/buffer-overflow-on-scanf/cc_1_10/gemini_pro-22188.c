//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int vertex1;
    int vertex2;
} Edge;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

typedef struct {
    int color;
    bool visited;
} Vertex;

Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &graph->edges[i].vertex1, &graph->edges[i].vertex2);
    }

    return graph;
}

void free_graph(Graph* graph) {
    free(graph);
}

Vertex* create_vertex(int color, bool visited) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->color = color;
    vertex->visited = visited;

    return vertex;
}

void free_vertex(Vertex* vertex) {
    free(vertex);
}

bool is_safe(Graph* graph, Vertex* vertices, int vertex, int color) {
    for (int i = 0; i < graph->num_edges; i++) {
        Edge edge = graph->edges[i];
        if (edge.vertex1 == vertex || edge.vertex2 == vertex) {
            int other_vertex = edge.vertex1 == vertex ? edge.vertex2 : edge.vertex1;
            if (vertices[other_vertex].color == color) {
                return false;
            }
        }
    }

    return true;
}

bool graph_coloring(Graph* graph, Vertex* vertices, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= graph->num_vertices; color++) {
        if (is_safe(graph, vertices, vertex, color)) {
            vertices[vertex].color = color;
            if (graph_coloring(graph, vertices, vertex + 1)) {
                return true;
            }
            vertices[vertex].color = 0;
        }
    }

    return false;
}

int main() {
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);

    Graph* graph = create_graph(num_vertices, num_edges);

    Vertex* vertices = (Vertex*)malloc(num_vertices * sizeof(Vertex));
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = *create_vertex(0, false);
    }

    if (graph_coloring(graph, vertices, 0)) {
        for (int i = 0; i < num_vertices; i++) {
            printf("%d ", vertices[i].color);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored.\n");
    }

    free_graph(graph);
    for (int i = 0; i < num_vertices; i++) {
        free_vertex(&vertices[i]);
    }
    free(vertices);

    return 0;
}