//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000

typedef struct {
    int node;
    int cost;
} Edge;

int visited[100];
int parent[100];
int edge_count = 0;
int num_vertices = 0;
Edge* edges = NULL;

int dijkstra(int source) {
    int min_cost = INF;
    int min_cost_node = -1;

    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    visited[source] = 1;
    parent[source] = source;

    for (int i = 0; i < num_vertices; i++) {
        int min_node = -1;
        int min_cost = INF;

        for (int j = 0; j < num_vertices; j++) {
            if (!visited[j] && edges[j].cost < min_cost) {
                min_node = j;
                min_cost = edges[j].cost;
            }
        }

        if (min_cost!= INF) {
            visited[min_node] = 1;
            parent[min_node] = min_node;

            for (int k = 0; k < num_vertices; k++) {
                Edge* edge = &edges[k];

                if (edge->node == min_node && edge->cost > min_cost + edge->cost) {
                    edge->cost = min_cost + edge->cost;
                }
            }
        }
    }

    return min_cost_node;
}

void add_edge(int src, int dest, int cost) {
    if (edge_count == num_vertices) {
        printf("Maximum number of vertices reached. Cannot add more edges.\n");
        return;
    }

    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->node = dest;
    edge->cost = cost;

    if (edges == NULL) {
        edges = (Edge*)malloc(num_vertices * sizeof(Edge));
    } else {
        edges = (Edge*)realloc(edges, (edge_count + 1) * sizeof(Edge));
    }

    edges[edge_count++] = *edge;
}

int main() {
    int num_vertices, num_edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    num_vertices++;
    num_edges++;

    edges = (Edge*)malloc(num_vertices * sizeof(Edge));

    printf("Enter the edges (source, destination, cost):\n");
    for (int i = 0; i < num_edges; i++) {
        int src, dest, cost;

        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &cost);

        add_edge(src, dest, cost);
    }

    int source = dijkstra(0);

    printf("The shortest path from vertex 0 to %d is: ", source);
    for (int i = 0; i < num_vertices; i++) {
        if (parent[i] == source) {
            printf("%d ", i);
        }
    }

    printf("\n");

    free(edges);
    return 0;
}