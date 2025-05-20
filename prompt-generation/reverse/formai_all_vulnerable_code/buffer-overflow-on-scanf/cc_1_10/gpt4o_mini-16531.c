//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src); // Since it's undirected
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void displayGraph(Graph* graph) {
    printf("Graph shape:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void shapeShiftDisplay(Graph* graph) {
    printf("\nShape-shifted Graph Representation:\n");
    printf("1. Number of vertices: %d\n", graph->numVertices);
    
    int totalEdges = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            totalEdges++;
            temp = temp->next;
        }
    }
    totalEdges /= 2; // Since we counted edges twice

    printf("2. Total edges: %d\n", totalEdges);
    
    if (totalEdges > graph->numVertices) {
        printf("3. Dense Graph Representation:\n");
        printf("      *  *  *  *\n"); // Just a simple symbolic representation
    } else {
        printf("3. Sparse Graph Representation:\n");
        printf("      *\n"); // Another simple representation
    }
    
    printf("Graph Connections:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d connects to: ", v);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Should be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }
    
    Graph* graph = createGraph(vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge. Please enter vertices between 0 and %d.\n", vertices - 1);
            i--; // Decrement count to redo this edge
            continue;
        }
        addEdge(graph, src, dest);
    }
    
    displayGraph(graph);
    shapeShiftDisplay(graph);
    
    // Cleanup memory
    for (int v = 0; v < vertices; v++) {
        Node* temp = graph->adjLists[v];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
    
    return 0;
}