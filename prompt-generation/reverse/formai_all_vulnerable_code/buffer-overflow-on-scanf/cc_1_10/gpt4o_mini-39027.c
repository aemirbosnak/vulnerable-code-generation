//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize visited array
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS)
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Function for resetting visited status
void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0; // Reset each vertex to unvisited
    }
}

// Breadth First Search (BFS)
void BFS(Graph* graph, int startVertex) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    
    queue[rear++] = startVertex;
    graph->visited[startVertex] = 1;

    printf("BFS starting from vertex %d:\n", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int connectedVertex = temp->vertex;
            if (!graph->visited[connectedVertex]) {
                graph->visited[connectedVertex] = 1;
                queue[rear++] = connectedVertex;
            }
            temp = temp->next;
        }
    }
}

// Main function to demonstrate graph functionality
int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nGraph adjacency list:\n");
    printGraph(graph);

    printf("\nDepth First Search (DFS):\n");
    DFS(graph, 0);
    resetVisited(graph);

    printf("\nBreadth First Search (BFS):\n");
    BFS(graph, 0);

    // Free memory
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}