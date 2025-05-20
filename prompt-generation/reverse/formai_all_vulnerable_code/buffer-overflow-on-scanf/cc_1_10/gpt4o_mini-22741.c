//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void releaseGraph(Graph* graph);
bool isGraphNull(Graph* graph);
void paranoidCheckVertex(int vertex, int limit);

int main() {
    int vertices, src, dest;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    paranoidCheckVertex(vertices, MAX_VERTICES);
    
    Graph* graph = createGraph(vertices);
    printf("Graph created successfully.\n");

    while (true) {
        printf("1. Add Edge\n2. Remove Edge\n3. Display Graph\n4. Exit\nChoose an option: ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter source and destination vertices (0-%d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                paranoidCheckVertex(src, vertices);
                paranoidCheckVertex(dest, vertices);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices (0-%d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                paranoidCheckVertex(src, vertices);
                paranoidCheckVertex(dest, vertices);
                removeEdge(graph, src, dest);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                releaseGraph(graph);
                printf("Graph memory released. Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

Graph* createGraph(int vertices) {
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices specified! Must be between 1 and %d.\n", MAX_VERTICES);
        exit(EXIT_FAILURE);
    }
    
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        fprintf(stderr, "Error: Memory allocation failed for graph.\n");
        exit(EXIT_FAILURE);
    }
    
    graph->vertices = vertices;
    
    // Initialize adjacency matrix to false
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    if (isGraphNull(graph)) return;
    
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true; // Undirected graph
    printf("Edge between %d and %d added successfully.\n", src, dest);
}

void removeEdge(Graph* graph, int src, int dest) {
    if (isGraphNull(graph)) return;
    
    if (graph->adjMatrix[src][dest] == false) {
        printf("Error: Edge between %d and %d does not exist!\n", src, dest);
        return;
    }
    
    graph->adjMatrix[src][dest] = false;
    graph->adjMatrix[dest][src] = false; // Undirected graph
    printf("Edge between %d and %d removed successfully.\n", src, dest);
}

void displayGraph(Graph* graph) {
    if (isGraphNull(graph)) return;
    
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

void releaseGraph(Graph* graph) {
    if (isGraphNull(graph)) return;
    free(graph);
    graph = NULL; // Let's not leave dangling pointers
}

bool isGraphNull(Graph* graph) {
    if (graph == NULL) {
        fprintf(stderr, "Error: Graph instance is null. Cannot proceed with operation!\n");
        return true;
    }
    return false;
}

void paranoidCheckVertex(int vertex, int limit) {
    if (vertex < 0 || vertex >= limit) {
        fprintf(stderr, "Error: Vertex index %d is out of bounds (0 to %d).\n", vertex, limit - 1);
        exit(EXIT_FAILURE);
    }
}