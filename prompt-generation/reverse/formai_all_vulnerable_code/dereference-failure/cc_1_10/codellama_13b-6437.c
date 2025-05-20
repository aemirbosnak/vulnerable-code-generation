//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: paranoid
/*
 * paranoid_graph.c
 *
 * A paranoid C Graph representation example program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/* Graph structure */
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int num_vertices;
    int num_edges;
    GraphNode* adjacency_list;
} Graph;

/* Graph operations */
Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    assert(graph != NULL);

    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adjacency_list = malloc(num_vertices * sizeof(GraphNode));
    assert(graph->adjacency_list != NULL);

    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_list[i].vertex = i;
        graph->adjacency_list[i].next = NULL;
    }

    return graph;
}

void add_edge(Graph* graph, int vertex1, int vertex2) {
    assert(graph != NULL);
    assert(vertex1 >= 0 && vertex1 < graph->num_vertices);
    assert(vertex2 >= 0 && vertex2 < graph->num_vertices);

    GraphNode* node1 = &graph->adjacency_list[vertex1];
    GraphNode* node2 = &graph->adjacency_list[vertex2];

    node1->next = node2;
    graph->num_edges++;
}

void remove_edge(Graph* graph, int vertex1, int vertex2) {
    assert(graph != NULL);
    assert(vertex1 >= 0 && vertex1 < graph->num_vertices);
    assert(vertex2 >= 0 && vertex2 < graph->num_vertices);

    GraphNode* node1 = &graph->adjacency_list[vertex1];
    GraphNode* node2 = &graph->adjacency_list[vertex2];

    node1->next = NULL;
    graph->num_edges--;
}

void print_graph(Graph* graph) {
    assert(graph != NULL);

    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        GraphNode* node = &graph->adjacency_list[i];
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    print_graph(graph);

    remove_edge(graph, 0, 2);
    remove_edge(graph, 1, 2);

    print_graph(graph);

    free(graph->adjacency_list);
    free(graph);

    return 0;
}