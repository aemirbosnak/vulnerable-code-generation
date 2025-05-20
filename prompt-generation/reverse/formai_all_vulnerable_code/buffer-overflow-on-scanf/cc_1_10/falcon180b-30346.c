//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// A utility function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// A utility function to print the graph
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// A utility function to traverse the graph using BFS
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int u, v;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);

        for (v = 0; v < MAX_VERTICES; v++) {
            if (graph[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &startVertex);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Print the graph
    printf("The graph is:\n");
    printGraph(graph);

    // Traverse the graph using BFS
    printf("\nBFS traversal starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}