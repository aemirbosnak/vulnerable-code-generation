//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 9

// Create a structure for a graph vertex
struct Vertex {
    int city;
    struct Vertex* parent;
};

// Create an adjacency list representation of the graph
struct Vertex* createGraph(int cities[], int n) {
    struct Vertex* graph = (struct Vertex*) malloc(n * sizeof(struct Vertex));

    // Initialize all vertices as unvisited
    for (int i = 0; i < n; i++) {
        graph[i].city = cities[i];
        graph[i].parent = NULL;
    }

    return graph;
}

// Perform depth-first search on the graph starting from a given vertex
void dfs(struct Vertex* graph, int start, int end) {
    struct Vertex* current = graph + start;
    while (current->parent!= NULL) {
        current = current->parent;
    }

    printf("%d ", current->city);
    current->parent = graph + end;
}

// Main function to test the graph implementation
int main() {
    int cities[V] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(cities) / sizeof(cities[0]);

    struct Vertex* graph = createGraph(cities, n);

    int start = 0;
    int end = 8;

    dfs(graph, start, end);

    return 0;
}