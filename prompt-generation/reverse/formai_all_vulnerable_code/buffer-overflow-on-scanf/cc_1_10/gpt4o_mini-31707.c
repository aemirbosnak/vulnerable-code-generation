//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200
#define INF 999999

typedef struct {
    int vertices[MAX_VERTICES];
    int edgeMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
    int edgeCount;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int weight);
void displayGraph(Graph* graph);
void dijkstra(Graph* graph, int startVertex);
void cleanupGraph(Graph* graph);

int main() {
    int vertices, choice, src, dest, weight; 
    Graph* graph;

    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    graph = createGraph(vertices);

    while (1) {
        printf("\n1. Add Edge\n2. Display Graph\n3. Dijkstra's Algorithm\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                printf("Enter weight: ");
                scanf("%d", &weight);
                addEdge(graph, src, dest, weight);
                break;

            case 2:
                displayGraph(graph);
                break;

            case 3:
                printf("Enter starting vertex for Dijkstra: ");
                scanf("%d", &src);
                dijkstra(graph, src);
                break;

            case 4:
                cleanupGraph(graph);
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertices;
    graph->edgeCount = 0;

    for (int i = 0; i < vertices; i++) {
        graph->vertices[i] = i;
        for (int j = 0; j < vertices; j++) {
            graph->edgeMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src >= graph->vertexCount || dest >= graph->vertexCount || src < 0 || dest < 0) {
        printf("Invalid edge!\n");
        return;
    }
    
    graph->edgeMatrix[src][dest] = weight;
    graph->edgeMatrix[dest][src] = weight; // For undirected graph
    graph->edgeCount++;
}

void displayGraph(Graph* graph) {
    printf("\nGraph adjacency matrix:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            if (graph->edgeMatrix[i][j] == INF)
                printf(" INF ");
            else
                printf("%4d ", graph->edgeMatrix[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(Graph* graph, int startVertex) {
    int distances[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    
    // Initialize distances
    for (int i = 0; i < graph->vertexCount; i++) {
        distances[i] = INF;
    }
    distances[startVertex] = 0;

    for (int count = 0; count < graph->vertexCount - 1; count++) {
        int minDistance = INF, minIndex;

        for (int v = 0; v < graph->vertexCount; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;

        for (int v = 0; v < graph->vertexCount; v++) {
            if (!visited[v] && graph->edgeMatrix[minIndex][v] != INF &&
                distances[minIndex] + graph->edgeMatrix[minIndex][v] < distances[v]) {
                distances[v] = distances[minIndex] + graph->edgeMatrix[minIndex][v];
            }
        }
    }

    printf("Distance from vertex %d:\n", startVertex);
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("Vertex %d: ", i);
        if (distances[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", distances[i]);
    }
}

void cleanupGraph(Graph* graph) {
    free(graph);
}