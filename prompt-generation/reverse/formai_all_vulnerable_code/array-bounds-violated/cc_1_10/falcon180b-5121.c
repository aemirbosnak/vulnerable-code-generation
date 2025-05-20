//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5
#define E 8

// Structure for a graph vertex
struct Vertex {
    int id;
    bool visited;
};

// Function to add an edge to the graph
void addEdge(struct Vertex graph[V], int u, int v) {
    graph[u].visited = true;
    graph[v].visited = true;
}

// Function to print the graph
void printGraph(struct Vertex graph[V]) {
    for (int i = 0; i < V; i++) {
        printf("%d ", graph[i].id);
    }
    printf("\n");
}

int main() {
    // Initialize the graph
    struct Vertex graph[V];
    for (int i = 0; i < V; i++) {
        graph[i].id = i;
        graph[i].visited = false;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printf("Graph representation:\n");
    printGraph(graph);

    // Traverse the graph using BFS
    int start = 0;
    int end = 4;
    int parent[V];
    int queue[V];
    int front = 0, rear = 0;
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    queue[rear++] = start;
    visited[start] = true;
    parent[start] = -1;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < V; v++) {
            if (graph[u].visited &&!visited[v]) {
                queue[rear++] = v;
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    int path[V];
    int k = end;
    while (k!= -1) {
        path[--k] = k;
    }
    printf("\nPath from %d to %d: ", start, end);
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}