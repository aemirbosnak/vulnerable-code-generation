//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define INF 9999

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    int adjacencies[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void create_graph(Graph *graph) {
    int i, j, num_edges;

    printf("Welcome to the Wasteland Survivor Network.\n");
    printf("Enter number of vertices in your network:\n");
    scanf("%d", &graph->num_vertices);

    printf("Enter number of edges in your network:\n");
    scanf("%d", &num_edges);

    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < graph->num_vertices; j++) {
            graph->adjacencies[i][j] = INF;
        }
    }

    printf("Enter edges and their weights (u v w):\n");

    Edge edge;

    for (i = 0; i < num_edges; i++) {
        scanf("%d%d%d", &edge.vertex, &edge.vertex + 1, &edge.weight);

        if (edge.vertex > edge.vertex + 1 || edge.vertex < 0 || edge.vertex + 1 > graph->num_vertices) {
            printf("Invalid vertex numbers. Try again.\n");
            i--;
            continue;
        }

        graph->adjacencies[edge.vertex][edge.vertex + 1] = edge.weight;
        graph->adjacencies[edge.vertex + 1][edge.vertex] = edge.weight;
    }
}

void print_graph(Graph graph) {
    int i, j;

    printf("\nWasteland Survivor Network:\n\n");

    for (i = 0; i < graph.num_vertices; i++) {
        printf("Vertex %d: ", i);

        for (j = 0; j < graph.num_vertices; j++) {
            if (graph.adjacencies[i][j] != INF) {
                printf("(%d, %d) ", j, graph.adjacencies[i][j]);
            }
        }

        printf("\n");
    }
}

int main() {
    Graph graph;

    create_graph(&graph);
    print_graph(graph);

    return 0;
}