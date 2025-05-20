//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a node
struct Node* createNode(int vertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function for breadth-first search
void bfs(struct Graph* graph, int startVertex) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int adjVertex = adjList->vertex;

            // If an adjacent vertex has not been visited, mark it and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
}

// Function to free memory of the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* adjList = graph->adjLists[i];
        while (adjList != NULL) {
            struct Node* temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function
int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    // Free memory allocated for the graph
    freeGraph(graph);

    return 0;
}