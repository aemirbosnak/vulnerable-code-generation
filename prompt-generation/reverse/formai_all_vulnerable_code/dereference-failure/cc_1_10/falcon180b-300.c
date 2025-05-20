//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the graph structure
typedef struct graph {
    int vertices;
    Node** adjlist;
} Graph;

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = graph->adjlist[u];
    graph->adjlist[u] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i;
    for(i=0; i<graph->vertices; i++) {
        Node* node = graph->adjlist[i];
        printf("%d -> ", i);
        while(node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Function to perform breadth-first search on the graph
void bfs(Graph* graph, int start) {
    int visited[graph->vertices];
    int queue[graph->vertices];
    int front = 0, rear = 0;

    // Mark all nodes as unvisited
    for(int i=0; i<graph->vertices; i++) {
        visited[i] = 0;
    }

    // Add the starting node to the queue
    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear) {
        int u = queue[front++];
        Node* node = graph->adjlist[u];
        while(node!= NULL) {
            int v = node->data;
            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            node = node->next;
        }
    }
}

// Driver program
int main() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = 5;
    graph->adjlist = (Node**) malloc(graph->vertices * sizeof(Node*));
    for(int i=0; i<graph->vertices; i++) {
        graph->adjlist[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Graph representation:\n");
    printGraph(graph);

    int start = 2;
    printf("\nBFS traversal starting from vertex %d:\n", start);
    bfs(graph, start);

    return 0;
}