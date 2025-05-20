//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200
#define INF 99999

typedef struct {
    int vertex;
    int weight;
    struct adj_list_node* next;
} AdjListNode;

typedef struct {
    AdjListNode* head;
} AdjList;

typedef struct {
    int num_vertices;
    int num_edges;
    AdjList adj_list[MAX_VERTICES];
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i].head = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* new_node = (AdjListNode*)malloc(sizeof(AdjListNode));
    new_node->vertex = dest;
    new_node->weight = weight;
    new_node->next = graph->adj_list[src].head;
    graph->adj_list[src].head = new_node;
}

void dijkstra(Graph* graph, int start_vertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int num_visited = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start_vertex] = 0;

    AdjListNode* curr_node = graph->adj_list[start_vertex].head;

    while (curr_node!= NULL) {
        int neighbor = curr_node->vertex;
        int weight = curr_node->weight;

        if (distance[neighbor] > distance[start_vertex] + weight) {
            distance[neighbor] = distance[start_vertex] + weight;
        }

        curr_node = curr_node->next;
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        if (distance[i]!= INF) {
            printf("%d\t\t%d\n", i, distance[i]);
            num_visited++;
        }
    }

    if (num_visited == 0) {
        printf("No path found.\n");
    }
}

int main() {
    int num_vertices, num_edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    Graph* graph = create_graph(num_vertices);

    printf("Enter edges (vertex1 vertex2 weight):\n");
    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(graph, src, dest, weight);
    }

    int start_vertex;
    printf("Enter starting vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(graph, start_vertex);

    return 0;
}