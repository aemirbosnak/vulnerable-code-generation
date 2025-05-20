//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct graph {
    int V;
    int E;
    int** adj_matrix;
};

typedef struct graph Graph;

Graph* create_graph(int n)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->V = n;
    graph->E = 0;
    graph->adj_matrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        graph->adj_matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int u, int v)
{
    if (u < 0 || u >= graph->V || v < 0 || v >= graph->V) {
        printf("Invalid edge!\n");
        return;
    }
    graph->adj_matrix[u][v] = 1;
    graph->adj_matrix[v][u] = 1;
    graph->E++;
}

void display(Graph* graph)
{
    printf("Graph Adjacency Matrix:\n\n");

    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    Graph* graph = create_graph(n);

    printf("Enter vertices and edges, press -1 -1 to stop:\n");

    while (1) {
        scanf("%d %d", &u, &v);
        if (u == -1 && v == -1)
            break;
        add_edge(graph, u, v);
    }
    display(graph);
    return 0;
}