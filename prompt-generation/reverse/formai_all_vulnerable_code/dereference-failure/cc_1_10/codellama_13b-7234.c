//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

// Defining the structure for the graph nodes
typedef struct Node {
    int x;
    int y;
    int weight;
    int distance;
    int parent;
    int visited;
} Node;

// Defining the structure for the graph
typedef struct Graph {
    int numNodes;
    int numEdges;
    Node* nodes;
    int** edges;
} Graph;

// Function to create a new graph with n nodes and m edges
Graph* createGraph(int n, int m) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = n;
    graph->numEdges = m;
    graph->nodes = (Node*)malloc(n * sizeof(Node));
    graph->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->edges[i] = (int*)malloc(m * sizeof(int));
    }
    return graph;
}

// Function to add a node to the graph
void addNode(Graph* graph, int x, int y, int weight, int distance, int parent, int visited) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->weight = weight;
    node->distance = distance;
    node->parent = parent;
    node->visited = visited;
    graph->nodes[graph->numNodes++] = *node;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v, int weight) {
    graph->edges[u][v] = weight;
    graph->edges[v][u] = weight;
}

// Function to find the shortest path using A* algorithm
void findShortestPath(Graph* graph, int start, int end) {
    Node* nodes = graph->nodes;
    int numNodes = graph->numNodes;
    int* visited = (int*)malloc(numNodes * sizeof(int));
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }
    visited[start] = 1;
    int parent = -1;
    int distance = 0;
    while (parent != end) {
        int minDistance = INT_MAX;
        int minNode = -1;
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && nodes[i].distance < minDistance) {
                minDistance = nodes[i].distance;
                minNode = i;
            }
        }
        if (minNode == -1) {
            printf("No path found\n");
            return;
        }
        visited[minNode] = 1;
        parent = minNode;
        distance = nodes[minNode].distance;
        printf("Node %d with distance %d\n", minNode, distance);
    }
    printf("Path found with distance %d\n", distance);
}

// Driver code
int main() {
    // Creating a graph with 5 nodes and 6 edges
    Graph* graph = createGraph(5, 6);
    addNode(graph, 0, 0, 0, 0, -1, 0);
    addNode(graph, 1, 1, 1, 1, -1, 0);
    addNode(graph, 2, 2, 2, 2, -1, 0);
    addNode(graph, 3, 3, 3, 3, -1, 0);
    addNode(graph, 4, 4, 4, 4, -1, 0);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 4, 3);

    // Finding the shortest path using A* algorithm
    findShortestPath(graph, 0, 4);

    return 0;
}