//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10

// Function to check if the graph is full
bool isGraphFull(int graph[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j] == 0 && i != j) {
                return false;
            }
        }
    }
    return true;
}

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int source, int destination) {
    graph[source][destination] = 1;
    graph[destination][source] = 1;
}

// Function to remove an edge from the graph
void removeEdge(int graph[MAX_VERTICES][MAX_VERTICES], int source, int destination) {
    graph[source][destination] = 0;
    graph[destination][source] = 0;
}

// Function to check if there is a path between two vertices
bool hasPath(int graph[MAX_VERTICES][MAX_VERTICES], int source, int destination, bool visited[MAX_VERTICES]) {
    visited[source] = true;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[source][i] && hasPath(graph, i, destination, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = { { 0 } };
    int n, m, source, destination;

    // Initialize graph as empty

    scanf("%d %d", &n, &m);

    // Add edges to the graph
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    // Check if there is a path between two vertices
    scanf("%d %d", &source, &destination);
    bool visited[MAX_VERTICES] = { false };
    if (hasPath(graph, source, destination, visited)) {
        printf("Path exists.\n");
    } else {
        printf("Path does not exist.\n");
    }

    // Remove an edge from the graph
    removeEdge(graph, source, destination);

    // Check if there is a path between the same two vertices after removing the edge
    memset(visited, false, sizeof(visited));
    if (hasPath(graph, source, destination, visited)) {
        printf("Path exists even after removing the edge.\n");
    } else {
        printf("Path does not exist after removing the edge.\n");
    }

    return 0;
}