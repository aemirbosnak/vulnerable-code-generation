//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50
#define INF 99999

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph->adjacencyMatrix[i][j] = 0;
            } else {
                graph->adjacencyMatrix[i][j] = INF;
            }
        }
    }
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src < graph->numVertices && dest < graph->numVertices) {
        graph->adjacencyMatrix[src][dest] = weight;
        graph->adjacencyMatrix[dest][src] = weight; // Undirected graph
    } else {
        printf("Invalid edge!\n");
    }
}

void printGraph(Graph* graph) {
    printf("Adjacency Matrix Representation of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    
    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    
    distance[startVertex] = 0;

    for (int i = 0; i < graph->numVertices - 1; i++) {
        int minDistance = INF;
        int minIndex;

        for (int j = 0; j < graph->numVertices; j++) {
            if (visited[j] == 0 && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;

        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && graph->adjacencyMatrix[minIndex][j] != INF) {
                if (distance[minIndex] + graph->adjacencyMatrix[minIndex][j] < distance[j]) {
                    distance[j] = distance[minIndex] + graph->adjacencyMatrix[minIndex][j];
                }
            }
        }
    }

    printf("Vertex \t Distance from start vertex %d\n", startVertex);
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
}

int main() {
    Graph graph;
    int numVertices, numEdges;

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    initializeGraph(&graph, numVertices);

    printf("Enter number of edges (max %d): ", MAX_EDGES);
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        printf("Enter edge %d (src dest weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    printGraph(&graph);

    int startVertex;
    printf("Enter the starting vertex for Dijkstra's algorithm: ");
    scanf("%d", &startVertex);

    dijkstra(&graph, startVertex);

    return 0;
}