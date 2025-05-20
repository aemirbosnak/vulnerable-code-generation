//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct node {
    char name[20];
    int id;
    int degree;
    struct node *edges[10];
} Node;

Node *createNode(char name[], int id) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->degree = 0;
    for (int i = 0; i < 10; i++) {
        newNode->edges[i] = NULL;
    }
    return newNode;
}

void addEdge(Node *node1, Node *node2) {
    node1->degree++;
    node2->degree++;
    node1->edges[node1->degree - 1] = node2;
    node2->edges[node2->degree - 1] = node1;
}

void printGraph(Node *graph) {
    printf("Name\tID\tDegree\n");
    for (int i = 0; i < 10; i++) {
        if (graph->edges[i]!= NULL) {
            printf("%s\t%d\t%d\t", graph->name, graph->id, graph->degree);
            printf("->");
            printGraph(graph->edges[i]);
        }
    }
}

int main() {
    Node *graph = createNode("A", 1);
    Node *node1 = createNode("B", 2);
    Node *node2 = createNode("C", 3);
    Node *node3 = createNode("D", 4);

    addEdge(graph, node1);
    addEdge(graph, node2);
    addEdge(graph, node3);

    addEdge(node1, node2);
    addEdge(node1, node3);

    addEdge(node2, node3);

    printGraph(graph);
    return 0;
}