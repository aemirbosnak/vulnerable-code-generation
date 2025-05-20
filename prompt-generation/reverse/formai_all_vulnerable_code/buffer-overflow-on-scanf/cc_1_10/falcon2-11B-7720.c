//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: happy
;
// This is a happy code for C Graph representation example program.
// You will be amazed to see the happiness in this code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a single edge in the graph
void printEdge(int source, int dest, int weight) {
    printf("Edge from %d to %d with weight %d\n", source, dest, weight);
}

// Function to print the whole graph
void printGraph(int graph[][6], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Edge from %d to %d with weight %d\n", graph[i][0], graph[j][0], graph[i][1]);
        }
    }
}

// Function to add a new node to the graph
int addNode(int graph[][6], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][0] == graph[j][0]) {
                printf("Node already exists!\n");
                return 0;
            }
        }
    }
    return 1;
}

// Function to add an edge to the graph
int addEdge(int graph[][6], int n, int source, int dest, int weight) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][0] == source && graph[j][0] == dest) {
                printf("Edge already exists!\n");
                return 0;
            }
        }
    }
    graph[source][1] = dest;
    graph[dest][1] = source;
    graph[source][2] = weight;
    graph[dest][2] = weight;
    printf("Edge added successfully!\n");
    return 1;
}

// Function to delete a node from the graph
int deleteNode(int graph[][6], int n, int source) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][0] == source) {
                printf("Node not found!\n");
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][1] == source) {
                graph[i][1] = graph[i][2];
            }
            if (graph[i][2] == source) {
                graph[i][2] = graph[i][3];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][1] == graph[j][1]) {
                printf("Node not found!\n");
                return 0;
            }
        }
    }
    printf("Node deleted successfully!\n");
    return 1;
}

// Function to delete an edge from the graph
int deleteEdge(int graph[][6], int n, int source, int dest) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][0] == source && graph[j][0] == dest) {
                printf("Edge not found!\n");
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][1] == source || graph[i][1] == dest) {
                printf("Edge not found!\n");
                return 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][1] == graph[j][1]) {
                printf("Edge not found!\n");
                return 0;
            }
        }
    }
    graph[source][1] = graph[source][2];
    graph[dest][1] = graph[dest][2];
    graph[source][2] = graph[source][3];
    graph[dest][2] = graph[dest][3];
    printf("Edge deleted successfully!\n");
    return 1;
}

// Function to find the shortest path between two nodes in the graph
int findShortestPath(int graph[][6], int n, int source, int dest) {
    int visited[n];
    int distance[n];
    int i, j, k;
    visited[source] = 1;
    distance[source] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][0] == source && graph[j][0] == dest) {
                if (distance[i] == 0) {
                    distance[j] = distance[i] + graph[i][2];
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return -1;
        }
    }
    printf("Shortest path from %d to %d: %d\n", source, dest, distance[dest]);
    return distance[dest];
}

int main() {
    int graph[6][6];
    int n;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("Enter the weight of the edge from node %d to itself:\n", i);
                scanf("%d", &graph[i][j]);
            }
            else {
                printf("Enter the weight of the edge from node %d to node %d:\n", i, j);
                scanf("%d", &graph[i][j]);
            }
        }
    }
    printGraph(graph, n);
    printf("\n");
    int source, dest;
    printf("Enter the source and destination nodes:\n");
    scanf("%d %d", &source, &dest);
    int shortest_path = findShortestPath(graph, n, source, dest);
    if (shortest_path == -1) {
        printf("There is no path between %d and %d\n", source, dest);
    }
    else {
        printf("Shortest path from %d to %d: %d\n", source, dest, shortest_path);
    }
    return 0;
}