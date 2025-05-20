//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the graph
struct Node {
    int data;
    struct Node *next;
};

// Function to add a node to the graph
void addNode(struct Node **graph, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*graph == NULL) {
        *graph = newNode;
        return;
    }
    struct Node *lastNode = *graph;
    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to print the graph
void printGraph(struct Node *graph) {
    struct Node *currentNode = graph;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to traverse the graph recursively
void traverseGraph(struct Node *graph) {
    struct Node *currentNode = graph;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to find the shortest path between two nodes
void findShortestPath(struct Node *graph, int start, int end) {
    // TODO: Implement the shortest path algorithm
}

// Main function to test the graph functions
int main() {
    struct Node *graph = NULL;
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);
    addNode(&graph, 5);
    printGraph(graph);
    traverseGraph(graph);
    findShortestPath(graph, 1, 5);
    return 0;
}