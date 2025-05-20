//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    // Structure to represent a graph
    struct Graph {
        int numVertices;
        int numEdges;
        int** adjMatrix;
    };

    // Function to add an edge between two vertices
    void addEdge(struct Graph* graph, int src, int dest) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }

    // Function to print the graph
    void printGraph(struct Graph* graph) {
        printf("Graph has %d vertices and %d edges\n", graph->numVertices, graph->numEdges);
        for (int i = 0; i < graph->numVertices; i++) {
            for (int j = 0; j < graph->numVertices; j++) {
                if (graph->adjMatrix[i][j] == 1) {
                    printf("%d -> %d\n", i, j);
                }
            }
        }
    }

    // Driver code
    int main() {
        // Initialize graph
        struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
        graph->numVertices = 5;
        graph->numEdges = 0;
        graph->adjMatrix = (int**)malloc(graph->numVertices * sizeof(int*));
        for (int i = 0; i < graph->numVertices; i++) {
            graph->adjMatrix[i] = (int*)malloc(graph->numVertices * sizeof(int));
            for (int j = 0; j < graph->numVertices; j++) {
                graph->adjMatrix[i][j] = 0;
            }
        }

        // Add edges
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 4);
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 1, 4);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);

        // Print graph
        printGraph(graph);

        // Free memory
        for (int i = 0; i < graph->numVertices; i++) {
            free(graph->adjMatrix[i]);
        }
        free(graph->adjMatrix);
        free(graph);

        return 0;
    }