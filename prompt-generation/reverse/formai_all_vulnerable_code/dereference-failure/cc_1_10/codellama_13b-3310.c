//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

struct Graph {
    int numVertices;
    struct GraphNode** adjLists;
};

struct GraphNode* createGraphNode(int vertex) {
    struct GraphNode* node = malloc(sizeof(struct GraphNode));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = malloc(numVertices * sizeof(struct GraphNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    struct GraphNode* newNode = createGraphNode(endVertex);
    newNode->next = graph->adjLists[startVertex];
    graph->adjLists[startVertex] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct GraphNode* node = graph->adjLists[i];
        printf("%d: ", i);
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    printGraph(graph);
    return 0;
}