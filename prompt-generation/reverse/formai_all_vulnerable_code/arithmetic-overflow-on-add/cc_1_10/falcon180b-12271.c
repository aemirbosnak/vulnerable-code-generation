//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

typedef struct {
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

void generate_random_graph(Graph *graph, int num_nodes) {
    srand(time(NULL));
    graph->num_edges = rand() % num_nodes + 1;
    for (int i = 0; i < graph->num_edges; i++) {
        int from = rand() % num_nodes;
        int to = rand() % num_nodes;
        while (to == from) {
            to = rand() % num_nodes;
        }
        graph->edges[i].from = from;
        graph->edges[i].to = to;
        graph->edges[i].weight = rand() % 100;
    }
}

int dijkstra(Graph *graph, int start_node, int end_node) {
    int num_nodes = graph->num_edges;
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    int previous[MAX_NODES];

    for (int i = 0; i < num_nodes; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    distances[start_node] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
        int min_distance = INT_MAX;
        int u = -1;

        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < num_nodes; v++) {
            if (!visited[v]) {
                int new_distance = distances[u] + graph->edges[v * num_nodes + u].weight;

                if (new_distance < distances[v]) {
                    distances[v] = new_distance;
                    previous[v] = u;
                }
            }
        }
    }

    return distances[end_node];
}

int main() {
    Graph graph;
    generate_random_graph(&graph, 10);

    int start_node = 0;
    int end_node = 9;

    int shortest_path_length = dijkstra(&graph, start_node, end_node);

    printf("Shortest path: %d\n", shortest_path_length);

    return 0;
}