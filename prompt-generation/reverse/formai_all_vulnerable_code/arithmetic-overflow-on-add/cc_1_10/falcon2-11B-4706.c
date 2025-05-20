//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 100
#define K 10

// Define the graph structure
typedef struct {
    int vertices;
    int edges;
    int* adjacencyList;
    int* adjacencyListWeight;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices, int edges) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->adjacencyList = (int*) malloc(vertices * sizeof(int));
    graph->adjacencyListWeight = (int*) malloc(vertices * sizeof(int));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v, int weight) {
    graph->adjacencyList[u]++;
    graph->adjacencyListWeight[u] += weight;
    graph->adjacencyList[v]++;
    graph->adjacencyListWeight[v] += weight;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Vertices: %d\n", graph->vertices);
    printf("Edges: %d\n", graph->edges);
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d (%d)\n", i, graph->adjacencyList[i]);
    }
    printf("Adjacency List Weight:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d (%d)\n", i, graph->adjacencyListWeight[i]);
    }
}

// Function to print the graph in adjacency list format
void printAdjacencyList(Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d (%d)\n", i, graph->adjacencyList[i]);
    }
}

// Function to print the graph in adjacency list weight format
void printAdjacencyListWeight(Graph* graph) {
    printf("Adjacency List Weight:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d (%d)\n", i, graph->adjacencyListWeight[i]);
    }
}

// Function to find the shortest path from vertex 0 to vertex N-1
void findShortestPath(Graph* graph, int source, int target) {
    int* distance = (int*) malloc(N * sizeof(int));
    int* previous = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        distance[i] = 10000;
        previous[i] = -1;
    }
    distance[source] = 0;
    int* queue = (int*) malloc(N * sizeof(int));
    int front = 0;
    int rear = 0;
    queue[rear++] = source;
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyList[current] > 0) {
                int neighbor = graph->adjacencyList[current];
                if (distance[neighbor] > distance[current] + graph->adjacencyListWeight[current]) {
                    distance[neighbor] = distance[current] + graph->adjacencyListWeight[current];
                    previous[neighbor] = current;
                }
            }
        }
    }
    printf("Shortest path from vertex %d to vertex %d:\n", source, target);
    int current = target;
    while (current!= -1) {
        printf("%d -> ", current);
        current = previous[current];
    }
    printf("End\n");
}

int main() {
    int vertices = N;
    int edges = K;
    Graph* graph = createGraph(vertices, edges);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 3, 15);
    addEdge(graph, 3, 4, 20);
    addEdge(graph, 4, 5, 25);
    addEdge(graph, 5, 0, 30);
    printf("Graph:\n");
    printGraph(graph);
    printf("Adjacency List:\n");
    printAdjacencyList(graph);
    printf("Adjacency List Weight:\n");
    printAdjacencyListWeight(graph);
    printf("Shortest path from vertex 0 to vertex %d:\n", N - 1);
    findShortestPath(graph, 0, N - 1);
    return 0;
}