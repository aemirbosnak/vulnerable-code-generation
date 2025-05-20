//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_V 100
#define MAX_E 100

// Data structure for graph representation
typedef struct {
    int V;
    int **adj;
} Graph;

// Function to create a graph
Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->adj[u] = (int *) realloc(graph->adj[u], (graph->adj[u]? graph->adj[u][0] : 0) + 1);
    graph->adj[u][graph->adj[u][0]] = v;
    graph->adj[v] = (int *) realloc(graph->adj[v], (graph->adj[v]? graph->adj[v][0] : 0) + 1);
    graph->adj[v][graph->adj[v][0]] = u;
}

// Function to print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; graph->adj[i][j]!= -1; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// Function to perform DFS on the graph
void DFS(Graph *graph, int v, bool visited[], int *time) {
    visited[v] = true;
    (*time)++;
    printf("Vertex %d is visited at %d\n", v, *time);
    for (int i = 0; graph->adj[v][i]!= -1; i++) {
        if (!visited[graph->adj[v][i]]) {
            DFS(graph, graph->adj[v][i], visited, time);
        }
    }
}

// Function to perform BFS on the graph
void BFS(Graph *graph, int v) {
    bool visited[graph->V];
    int time = 0;
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    DFS(graph, v, visited, &time);
}

// Main function
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    Graph *graph = createGraph(V);
    printf("Enter the edges (u v): ");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printf("Graph representation:\n");
    printGraph(graph);
    printf("DFS traversal:\n");
    BFS(graph, 0);
    return 0;
}