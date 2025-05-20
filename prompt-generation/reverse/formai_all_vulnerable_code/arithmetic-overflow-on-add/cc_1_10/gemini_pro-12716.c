//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct node {
    int vertex;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t *adj_list[MAX_VERTICES];
} graph_t;

graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }

    graph->num_vertices = num_vertices;
    graph->num_edges = 0;

    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void destroy_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *node = graph->adj_list[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }

    free(graph);
}

int add_edge(graph_t *graph, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= graph->num_vertices || vertex2 < 0 || vertex2 >= graph->num_vertices) {
        return -1;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->vertex = vertex2;
    new_node->next = graph->adj_list[vertex1];
    graph->adj_list[vertex1] = new_node;

    graph->num_edges++;

    return 0;
}

int remove_edge(graph_t *graph, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= graph->num_vertices || vertex2 < 0 || vertex2 >= graph->num_vertices) {
        return -1;
    }

    node_t *node = graph->adj_list[vertex1];
    node_t *prev = NULL;

    while (node != NULL) {
        if (node->vertex == vertex2) {
            if (prev == NULL) {
                graph->adj_list[vertex1] = node->next;
            } else {
                prev->next = node->next;
            }

            free(node);

            graph->num_edges--;

            return 0;
        }

        prev = node;
        node = node->next;
    }

    return -1;
}

int get_num_vertices(graph_t *graph) {
    return graph->num_vertices;
}

int get_num_edges(graph_t *graph) {
    return graph->num_edges;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);

        node_t *node = graph->adj_list[i];
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }

        printf("\n");
    }
}

int main() {
    graph_t *graph = create_graph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);

    print_graph(graph);

    printf("Number of vertices: %d\n", get_num_vertices(graph));
    printf("Number of edges: %d\n", get_num_edges(graph));

    remove_edge(graph, 2, 3);

    print_graph(graph);

    destroy_graph(graph);

    return 0;
}