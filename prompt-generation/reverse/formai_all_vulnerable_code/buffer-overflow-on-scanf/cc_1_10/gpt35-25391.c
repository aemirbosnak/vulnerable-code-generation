//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to store graph
int vertices = 0; // number of vertices in the graph

// function to add edge between two vertices
void addEdge(int source, int destination) {
    if(source >= vertices || destination >= vertices) { // invalid vertices
        printf("Invalid vertices!\n");
        return;
    }
    graph[source][destination] = 1;
    graph[destination][source] = 1; // since it is an undirected graph
}

// function to remove edge between two vertices
void removeEdge(int source, int destination) {
    if(source >= vertices || destination >= vertices) { // invalid vertices
        printf("Invalid vertices!\n");
        return;
    }
    graph[source][destination] = 0;
    graph[destination][source] = 0; // since it is an undirected graph
}

// function to display graph in matrix form
void displayGraph() {
    printf("Adjacency matrix representation of graph:\n");
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices in graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    // initialize graph
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // add edges to the graph
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 0);
    addEdge(1, 4);

    // display initial graph
    displayGraph();

    // remove edges from the graph
    removeEdge(1, 2);
    removeEdge(0, 4);

    // display modified graph
    displayGraph();

    return 0;
}