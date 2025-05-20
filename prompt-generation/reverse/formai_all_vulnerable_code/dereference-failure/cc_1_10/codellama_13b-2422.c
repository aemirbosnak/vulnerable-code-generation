//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Cryptic
/* Cryptic C Graph Representation Example */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Graph {
    int numNodes;
    Node *nodes;
} Graph;

void createGraph(Graph *g, int numNodes) {
    g->numNodes = numNodes;
    g->nodes = (Node *)malloc(numNodes * sizeof(Node));
    for (int i = 0; i < numNodes; i++) {
        g->nodes[i].data = i;
        g->nodes[i].next = NULL;
    }
}

void addEdge(Graph *g, int src, int dest) {
    Node *srcNode = &g->nodes[src];
    Node *destNode = &g->nodes[dest];
    srcNode->next = destNode;
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->numNodes; i++) {
        printf("%d -> ", g->nodes[i].data);
        Node *node = g->nodes[i].next;
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    createGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 0);
    printGraph(&g);
    return 0;
}