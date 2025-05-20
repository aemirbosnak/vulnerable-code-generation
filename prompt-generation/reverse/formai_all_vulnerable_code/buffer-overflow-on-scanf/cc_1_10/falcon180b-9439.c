//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the graph node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the graph
struct Graph {
    int V;
    struct Node** adj;
};

// Create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a new graph with given number of vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**) malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

// Add an edge from u to v with given weight
void addEdge(struct Graph* graph, int u, int v, int weight) {
    struct Node* node = newNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// Print the graph
void printGraph(struct Graph* graph) {
    int V = graph->V;
    printf("Graph representation:\n");
    for (int i = 0; i < V; i++) {
        struct Node* node = graph->adj[i];
        printf("Vertex %d is connected to: ", i);
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    struct Graph* graph = createGraph(V);
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u, v, weight);
    }
    printGraph(graph);
    return 0;
}