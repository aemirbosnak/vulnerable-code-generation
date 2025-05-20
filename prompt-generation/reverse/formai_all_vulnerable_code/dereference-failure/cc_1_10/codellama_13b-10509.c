//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
/*
* 🌟🎉 Unique C Graph Representation Example Program 🎉🌟
*
* This program demonstrates a unique graph representation in C.
* It uses a single linked list to store the graph nodes and
* a hashtable to store the adjacency list for each node.
*
* Author: [Your Name]
* Date: [Current Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a graph node
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Structure to represent a graph
typedef struct graph {
    Node** adjList;
    int numVertices;
} Graph;

// Hash function to hash a string to an integer
int hash(char* str) {
    int hash = 0;
    for (int i = 0; i < strlen(str); i++) {
        hash += str[i];
    }
    return hash % 100;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(Graph* graph, int src, int dest) {
    Node* node = malloc(sizeof(Node));
    node->vertex = dest;
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
}

// Function to find an edge in a graph
bool findEdge(Graph* graph, int src, int dest) {
    Node* node = graph->adjList[src];
    while (node != NULL) {
        if (node->vertex == dest) {
            return true;
        }
        node = node->next;
    }
    return false;
}

// Function to print the adjacency list of a graph
void printAdjList(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* node = graph->adjList[i];
        while (node != NULL) {
            printf("%d -> ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* node = graph->adjList[i];
        while (node != NULL) {
            printf("%d -> ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);

    // Print the adjacency list of the graph
    printAdjList(graph);

    // Print the graph
    printGraph(graph);

    // Check if an edge exists
    bool exists = findEdge(graph, 0, 1);
    printf("Edge (0, 1) exists: %s\n", exists ? "Yes" : "No");

    // Free the graph
    free(graph->adjList);
    free(graph);

    return 0;
}