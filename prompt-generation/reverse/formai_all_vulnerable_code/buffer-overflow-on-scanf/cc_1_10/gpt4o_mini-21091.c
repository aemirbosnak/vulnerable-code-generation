//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    
    // Initialize adjacency matrix to 0
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int startVertex, int endVertex) {
    g->adjMatrix[startVertex][endVertex] = 1; // Directed graph
    g->adjMatrix[endVertex][startVertex] = 1; // Uncomment for undirected graph
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph *g, int vertex, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] && !visited[i]) {
            depthFirstSearch(g, i, visited);
        }
    }
}

void DFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Reset visited array
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    depthFirstSearch(g, startVertex, visited);
    printf("\n");
}

void breadthFirstSearch(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Reset visited array
    int queue[MAX_VERTICES], front = 0, rear = -1;
    
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    
    printf("\n");
}

int main() {
    Graph g;
    int vertices;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    initGraph(&g, vertices);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;
        printf("Enter edge (start end): ");
        scanf("%d %d", &startVertex, &endVertex);
        
        if (startVertex < 0 || startVertex >= vertices || endVertex < 0 || endVertex >= vertices) {
            printf("Invalid edge! Vertices must be in range [0, %d).\n", vertices);
            i--; // Don't count this invalid edge
            continue;
        }

        addEdge(&g, startVertex, endVertex);
    }

    printf("\nAdjacency Matrix Representation of the Graph:\n");
    printGraph(&g);

    int startVertex;
    printf("Enter a starting vertex for DFS: ");
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    DFS(&g, startVertex);

    printf("\n");
    printf("Enter a starting vertex for BFS: ");
    scanf("%d", &startVertex);
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    breadthFirstSearch(&g, startVertex);

    return 0;
}