//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct graph {
    int vertices;
    int edges;
    int** adjacency_matrix;
} Graph;

void read_graph(Graph* graph, int vertices, int edges) {
    graph->vertices = vertices;
    graph->edges = edges;
    graph->adjacency_matrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(edges * sizeof(int));
    }

    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph->adjacency_matrix[v1][i] = v2;
    }
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->edges; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int** graph_to_adjacency_list(Graph* graph) {
    int** adjacency_list = (int**)malloc(graph->vertices * sizeof(int*));

    for (int i = 0; i < graph->vertices; i++) {
        adjacency_list[i] = (int*)malloc(graph->edges * sizeof(int));
    }

    for (int i = 0; i < graph->edges; i++) {
        int v1, v2;
        v1 = graph->adjacency_matrix[v1][i];
        adjacency_list[v1][i] = v2;
    }

    return adjacency_list;
}

int** color_graph(Graph* graph, int** adjacency_list, int** colors) {
    int** colored_graph = (int**)malloc(graph->vertices * sizeof(int*));

    for (int i = 0; i < graph->vertices; i++) {
        colored_graph[i] = (int*)malloc(graph->edges * sizeof(int));
    }

    for (int i = 0; i < graph->edges; i++) {
        colored_graph[i][i] = colors[i][0];
    }

    for (int i = 0; i < graph->edges; i++) {
        int v1, v2;
        v1 = adjacency_list[i][0];
        v2 = adjacency_list[i][1];

        if (colors[i][0] == colors[v2][0]) {
            colored_graph[v1][i] = colors[v2][1];
        } else {
            for (int j = 0; j < graph->vertices; j++) {
                if (colored_graph[j][i] == -1) {
                    colored_graph[j][i] = colors[i][1];
                    break;
                }
            }
        }
    }

    return colored_graph;
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    Graph* graph = (Graph*)malloc(1 * sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->adjacency_matrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(edges * sizeof(int));
    }

    read_graph(graph, vertices, edges);
    print_graph(graph);

    int** adjacency_list = graph_to_adjacency_list(graph);
    int** colors = (int**)malloc(edges * sizeof(int*));

    for (int i = 0; i < edges; i++) {
        colors[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &colors[i][0], &colors[i][1]);
    }

    int** colored_graph = color_graph(graph, adjacency_list, colors);
    print_graph(graph);

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->edges; j++) {
            printf("%d ", colored_graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}