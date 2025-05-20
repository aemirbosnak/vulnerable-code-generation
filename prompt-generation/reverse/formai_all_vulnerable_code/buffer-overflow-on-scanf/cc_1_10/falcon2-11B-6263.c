//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define INF 1000000

// Node structure
typedef struct {
    int vertex;
    int distance;
} Node;

// Graph structure
typedef struct {
    int num_vertices;
    int num_edges;
    int *edge_list;
    int *distances;
} Graph;

// Function to initialize a graph
void initialize_graph(Graph *g, int num_vertices) {
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->edge_list = (int *)malloc(num_vertices * sizeof(int));
    g->distances = (int *)calloc(num_vertices, sizeof(int));
}

// Function to add an edge to a graph
void add_edge(Graph *g, int source, int destination, int weight) {
    g->edge_list[g->num_edges] = destination;
    g->distances[destination] = INF;
    g->distances[source] = weight;
    g->num_edges++;
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra_shortest_path(Graph *g, int source) {
    int *distances = g->distances;
    int num_vertices = g->num_vertices;
    int num_edges = g->num_edges;
    int *edge_list = g->edge_list;
    bool *visited = (bool *)malloc(num_vertices * sizeof(bool));

    for (int i = 0; i < num_vertices; i++) {
        distances[i] = INF;
        visited[i] = false;
    }

    distances[source] = 0;

    for (int i = 0; i < num_vertices; i++) {
        int min_distance = INF;
        int min_index = -1;

        for (int j = 0; j < num_vertices; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }

        visited[min_index] = true;

        for (int j = 0; j < num_vertices; j++) {
            if (distances[j] > distances[min_index] + edge_list[j]) {
                distances[j] = distances[min_index] + edge_list[j];
            }
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");
}

// Function to display a graph
void display_graph(Graph *g) {
    int num_vertices = g->num_vertices;
    int num_edges = g->num_edges;
    int *edge_list = g->edge_list;

    printf("Graph:\n");

    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", i);

        for (int j = 0; j < num_vertices; j++) {
            if (edge_list[i] == j) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    Graph graph;
    initialize_graph(&graph, num_vertices);

    int source, destination;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    add_edge(&graph, source, destination, 10);

    dijkstra_shortest_path(&graph, source);

    display_graph(&graph);

    return 0;
}