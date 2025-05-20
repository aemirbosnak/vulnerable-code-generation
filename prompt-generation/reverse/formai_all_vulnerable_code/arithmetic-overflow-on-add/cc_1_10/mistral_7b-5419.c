//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int data;
    int visited;
} Vertex;

typedef struct {
    int source, destination, weight;
} Edge;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int num_vertices, num_edges;
    Edge adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void add_edge(Graph *graph, int source, int destination, int weight) {
    graph->adjacency_matrix[source][destination].source = source;
    graph->adjacency_matrix[source][destination].destination = destination;
    graph->adjacency_matrix[source][destination].weight = weight;

    graph->adjacency_matrix[destination][source].source = destination;
    graph->adjacency_matrix[destination][source].destination = source;
    graph->adjacency_matrix[destination][source].weight = weight;

    graph->num_edges++;
}

void print_graph(Graph graph) {
    printf("Adjacency Matrix Represented Graph:\n");
    for (int i = 0; i < graph.num_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < graph.num_vertices; j++) {
            if (graph.adjacency_matrix[i][j].weight != 0) {
                printf("(%d, %d, %d) ", i, j, graph.adjacency_matrix[i][j].weight);
            }
        }
    }
}

int main() {
    Graph my_graph;
    my_graph.num_vertices = 5;

    memset(my_graph.vertices, 0, sizeof(my_graph.vertices));

    add_edge(&my_graph, 0, 1, 4);
    add_edge(&my_graph, 0, 4, 2);
    add_edge(&my_graph, 1, 2, 5);
    add_edge(&my_graph, 1, 3, 3);
    add_edge(&my_graph, 2, 3, 1);
    add_edge(&my_graph, 2, 4, 6);
    add_edge(&my_graph, 3, 4, 7);

    print_graph(my_graph);

    return 0;
}