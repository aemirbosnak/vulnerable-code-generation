//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    char* label;
    struct node* next;
} Node;

typedef struct edge {
    int source;
    int target;
} Edge;

Node* head;
int numNodes;
int numEdges;
Edge* edges;

void createNode(Node* node, int id, char* label) {
    node->id = id;
    node->label = label;
    node->next = NULL;
}

void createEdge(Edge* edge, int source, int target) {
    edge->source = source;
    edge->target = target;
}

void addEdge(int source, int target) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    createEdge(newEdge, source, target);
    edges[numEdges] = *newEdge;
    numEdges++;
}

void addNode(int id, char* label) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    createNode(newNode, id, label);
    if (numNodes == 0) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    numNodes++;
}

void printGraph() {
    Node* current = head;
    while (current!= NULL) {
        printf("%s -> ", current->label);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* current;
    int numNodes, numEdges, source, target;
    Edge* edge;
    char* label;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        printf("Enter label for node %d: ", i);
        scanf("%s", label);
        addNode(i, label);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter source node for edge %d: ", i + 1);
        scanf("%d", &source);
        printf("Enter target node for edge %d: ", i + 1);
        scanf("%d", &target);
        addEdge(source, target);
    }

    printf("Graph representation:\n");
    printGraph();

    return 0;
}