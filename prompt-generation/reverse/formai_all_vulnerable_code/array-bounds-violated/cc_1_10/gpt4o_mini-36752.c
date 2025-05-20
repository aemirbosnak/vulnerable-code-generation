//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    // Initialize the graph with infinite distances
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j) {
                graph->vertices[i][j] = 0;
            } else {
                graph->vertices[i][j] = INT_MAX;
            }
        }
    }
    return graph;
}

void add_edge(Graph* graph, int start, int end, int weight) {
    graph->vertices[start][end] = weight;
    graph->vertices[end][start] = weight; // For undirected graph
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->vertices[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%3d ", graph->vertices[i][j]);
            }
        }
        printf("\n");
    }
}

void dijkstra(Graph* graph, int start_vertex) {
    int distances[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    
    for (int i = 0; i < graph->num_vertices; i++) {
        distances[i] = graph->vertices[start_vertex][i];
    }

    distances[start_vertex] = 0;
    visited[start_vertex] = 1;

    for (int i = 0; i < graph->num_vertices - 1; i++) {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < graph->num_vertices; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }

        if (min_index == -1) {
            break; // All reachable vertices visited or remaining vertices are unreachable
        }

        visited[min_index] = 1;

        for (int k = 0; k < graph->num_vertices; k++) {
            if (!visited[k] && graph->vertices[min_index][k] != INT_MAX && 
                distances[min_index] != INT_MAX && 
                distances[min_index] + graph->vertices[min_index][k] < distances[k]) {
                distances[k] = distances[min_index] + graph->vertices[min_index][k];
            }
        }
    }

    printf("Vertex\tDistance from Source (%d)\n", start_vertex);
    for (int i = 0; i < graph->num_vertices; i++) {
        if (distances[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, distances[i]);
        }
    }
}

int main() {
    int num_vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    Graph* graph = create_graph(num_vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int start, end, weight;
        printf("Enter edge (start end weight): ");
        scanf("%d %d %d", &start, &end, &weight);
        add_edge(graph, start, end, weight);
    }

    printf("Graph adjacency matrix:\n");
    print_graph(graph);

    int start_vertex;
    printf("Enter starting vertex for Dijkstra's algorithm: ");
    scanf("%d", &start_vertex);
    
    dijkstra(graph, start_vertex);

    // Cleanup
    free(graph);
    return 0;
}