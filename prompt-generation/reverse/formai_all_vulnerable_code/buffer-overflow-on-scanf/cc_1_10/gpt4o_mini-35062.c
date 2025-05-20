//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0; // Initialize all edges to 0
        }
    }

    return graph;
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    if (startVertex >= graph->numVertices || endVertex >= graph->numVertices)
        return;

    graph->adjacencyMatrix[startVertex][endVertex] = 1; // Add edge
    graph->adjacencyMatrix[endVertex][startVertex] = 1; // Assuming an undirected graph
}

void printGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS: ");

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Maximum number of vertices is %d\n", MAX_VERTICES);
        return 1;
    }

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(graph, startVertex, endVertex);
    }

    printGraph(graph);
    
    int visited[MAX_VERTICES] = {0};
    printf("DFS: ");
    depthFirstSearch(graph, 0, visited);
    printf("\n");

    breadthFirstSearch(graph, 0);

    free(graph);
    return 0;
}