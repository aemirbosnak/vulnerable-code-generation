//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NODE_COUNT 10
#define EDGE_COUNT 20
#define INF INT_MAX

typedef struct Edge {
    int weight;
    int to;
} Edge;

typedef struct Graph {
    int node_count;
    int edge_count;
    Edge* edges;
} Graph;

void generate_random_graph(Graph* graph) {
    graph->edges = (Edge*) malloc(graph->edge_count * sizeof(Edge));

    srand(time(NULL));

    for (int i = 0; i < graph->edge_count; i++) {
        int from = rand() % graph->node_count;
        int to = rand() % graph->node_count;
        int weight = rand() % 100;

        graph->edges[i] = (Edge) { weight, to };
    }
}

void dijkstra(Graph* graph, int start_node, int end_node) {
    int* distances = (int*) malloc(graph->node_count * sizeof(int));
    int* previous_nodes = (int*) malloc(graph->node_count * sizeof(int));

    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = INF;
        previous_nodes[i] = -1;
    }

    distances[start_node] = 0;

    int unvisited_node_count = graph->node_count;

    while (unvisited_node_count > 0) {
        int min_distance_node = -1;

        for (int i = 0; i < graph->node_count; i++) {
            if (distances[i] < INF && distances[i] <= distances[min_distance_node]) {
                min_distance_node = i;
            }
        }

        if (min_distance_node == -1) {
            break;
        }

        unvisited_node_count--;

        for (int j = 0; j < graph->node_count; j++) {
            Edge edge = graph->edges[min_distance_node * graph->node_count + j];

            if (distances[min_distance_node] + edge.weight < distances[j]) {
                distances[j] = distances[min_distance_node] + edge.weight;
                previous_nodes[j] = min_distance_node;
            }
        }
    }

    int path_node_count = 0;
    int path[graph->node_count];

    int current_node = end_node;

    while (current_node!= -1) {
        path[path_node_count++] = current_node;
        current_node = previous_nodes[current_node];
    }

    path_node_count--;

    for (int i = path_node_count; i >= 0; i--) {
        printf("%d ", path[i]);
    }

    printf("\n");

    free(distances);
    free(previous_nodes);
}

int main() {
    Graph graph = {.node_count = NODE_COUNT,.edge_count = EDGE_COUNT };

    generate_random_graph(&graph);

    dijkstra(&graph, 0, 9);

    return 0;
}