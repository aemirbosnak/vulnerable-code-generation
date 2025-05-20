//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    newNode = createNode(src); // For undirected graph
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    Node* adjList = graph->adjList[vertex];
    Node* temp = adjList;
    
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFSUtil(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(graph, startVertex, visited);
}

int main() {
    int vertices, edges, src, dest, startVertex;
    char choice[10];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    Graph* graph = createGraph(vertices);
    
    do {
        printf("1. Add Edge\n2. Display Graph\n3. Perform DFS\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%s", choice);
        
        switch (choice[0]) {
            case '1':
                printf("Enter source and destination (space-separated): ");
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    addEdge(graph, src, dest);
                } else {
                    printf("Invalid vertices!\n");
                }
                break;
            case '2':
                printf("Graph adjacency list:\n");
                printGraph(graph);
                break;
            case '3':
                printf("Enter start vertex for DFS: ");
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < vertices) {
                    printf("DFS starting from vertex %d:\n", startVertex);
                    DFS(graph, startVertex);
                    printf("\n");
                } else {
                    printf("Invalid start vertex!\n");
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        
        printf("\n");
    } while (choice[0] != '4');
    
    // Free allocated memory (not shown for brevity)
    
    return 0;
}