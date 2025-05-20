//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define INF 9999

typedef struct {
    int vertex;
    int weight;
    struct edge *next;
} Edge;

typedef struct {
    int vertex;
    int weight;
    struct vertex *next;
} Vertex;

typedef struct {
    Vertex *vertex;
    int count;
} Graph;

Graph *createGraph(int vertexCount) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertex = (Vertex *) malloc(vertexCount * sizeof(Vertex));
    graph->count = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        graph->vertex[i].vertex = i;
        graph->vertex[i].weight = 0;
        graph->vertex[i].next = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int source, int destination, int weight) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->vertex = destination;
    edge->weight = weight;
    edge->next = graph->vertex[source].next;
    graph->vertex[source].next = edge;
}

int dijkstra(Graph *graph, int start) {
    int distance[graph->count];
    int visited[graph->count];
    int i, j, k, u;

    for (i = 0; i < graph->count; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (i = 0; i < graph->count - 1; i++) {
        int minDistance = INF;
        int v = -1;

        for (j = 0; j < graph->count; j++) {
            if (!visited[j] && distance[j] <= minDistance) {
                minDistance = distance[j];
                v = j;
            }
        }

        visited[v] = 1;

        for (Edge *edge = graph->vertex[v].next; edge!= NULL; edge = edge->next) {
            int u = edge->vertex;
            int weight = edge->weight;

            if (!visited[u] && distance[v] + weight < distance[u]) {
                distance[u] = distance[v] + weight;
            }
        }
    }

    return distance[graph->count - 1];
}

int main() {
    int vertexCount, edgeCount, start;
    Graph *graph = NULL;
    Edge *edge = NULL;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertexCount);

    graph = createGraph(vertexCount);

    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter the edges (source destination weight):\n");
    while (edgeCount--) {
        scanf("%d %d %d", &start, &edge->vertex, &edge->weight);
        addEdge(graph, start, edge->vertex, edge->weight);
    }

    int shortestPath = dijkstra(graph, 0);

    printf("The shortest path from vertex 0 to %d is: %d\n", vertexCount - 1, shortestPath);

    return 0;
}