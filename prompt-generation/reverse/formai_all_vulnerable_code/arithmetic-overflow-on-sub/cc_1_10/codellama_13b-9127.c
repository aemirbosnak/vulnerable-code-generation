//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    // Structure to represent a graph
    struct Graph {
        int V; // Number of vertices
        int E; // Number of edges
        struct AdjList* adjList; // Pointer to an array containing adjacency lists
    };

    // Structure to represent an adjacency list
    struct AdjList {
        int size; // Size of the array
        int* arr; // Pointer to an array containing adjacency list
    };

    // Function to create a graph with V vertices and E edges
    struct Graph* createGraph(int V, int E) {
        struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
        graph->V = V;
        graph->E = E;
        graph->adjList = (struct AdjList*)malloc(V * sizeof(struct AdjList));
        return graph;
    }

    // Function to add an edge to a graph
    void addEdge(struct Graph* graph, int src, int dest) {
        struct AdjList* adjList = &graph->adjList[src];
        adjList->size++;
        adjList->arr = (int*)realloc(adjList->arr, adjList->size * sizeof(int));
        adjList->arr[adjList->size - 1] = dest;
    }

    // Function to print the graph
    void printGraph(struct Graph* graph) {
        for (int i = 0; i < graph->V; i++) {
            struct AdjList* adjList = &graph->adjList[i];
            printf("Vertex %d: ", i);
            for (int j = 0; j < adjList->size; j++) {
                printf("%d ", adjList->arr[j]);
            }
            printf("\n");
        }
    }

    int main() {
        struct Graph* graph = createGraph(5, 5);
        addEdge(graph, 0, 1);
        addEdge(graph, 1, 2);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        addEdge(graph, 4, 0);
        printGraph(graph);
        return 0;
    }