//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjacencyList[MAX_VERTICES];
    int degrees[MAX_VERTICES];
} Graph;

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->degrees[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;

    // Increment degrees
    graph->degrees[src]++;
    graph->degrees[dest]++;
}

// Function to display the adjacency list representation of the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to calculate and print degree distribution
void calculateDegreeDistribution(Graph* graph) {
    printf("\nDegree Distribution:\n");
    int degreeCount[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->degrees[i] < MAX_VERTICES) {
            degreeCount[graph->degrees[i]]++;
        }
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (degreeCount[i] > 0) {
            printf("Degree %d: %d vertices\n", i, degreeCount[i]);
        }
    }
}

// Main function to demonstrate graph operations
int main() {
    int numVertices, numEdges;
    
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);
    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            printf("Invalid edge (%d, %d).\n", src, dest);
            i--; // repeat the input
            continue;
        }
        addEdge(graph, src, dest);
    }

    printf("\nGraph representation:\n");
    displayGraph(graph);
    calculateDegreeDistribution(graph);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
    return 0;
}