//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the graph matrix and its size
#define SIZE 6
int graph[SIZE][SIZE] = {
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0}
};

// Define the queue and its head and tail
int queue[SIZE];
int head = 0;
int tail = 0;

// Define a boolean array to keep track of visited vertices
bool visited[SIZE];

// Depth first search (DFS) function
void DFS(int source, int destination) {
    // If the source and destination vertices are the same, print a message and return
    if (source == destination) {
        printf("We have arrived at the destination!\n");
        return;
    }
    // Mark the current vertex as visited
    visited[source] = true;
    // Loop through all the vertices connected to the current vertex
    for (int i = 0; i < SIZE; i++) {
        // If the vertex has not been visited and it is connected to the current vertex
        if (!visited[i] && graph[source][i]) {
            // Call the DFS function recursively
            DFS(i, destination);
            // If we have arrived at the destination, return
            if (visited[destination]) {
                return;
            }
        }
    }
}

// Breadth first search (BFS) function
void BFS(int source, int destination) {
    // Reset the queue and the visited array
    for (int i = 0; i < SIZE; i++) {
        queue[i] = -1;
        visited[i] = false;
    }
    // Add the source vertex to the queue and mark it as visited
    queue[tail++] = source;
    visited[source] = true;
    // Loop through all the vertices in the queue
    while (head != tail) {
        int current = queue[head++];
        // If we have arrived at the destination, print a message and return
        if (current == destination) {
            printf("We have arrived at the destination!\n");
            return;
        }
        // Loop through all the vertices connected to the current vertex
        for (int i = 0; i < SIZE; i++) {
            // If the vertex has not been visited and it is connected to the current vertex
            if (!visited[i] && graph[current][i]) {
                // Add the vertex to the queue and mark it as visited
                queue[tail++] = i;
                visited[i] = true;
            }
        }
    }
}

// Main function
int main() {
    int source, destination;
    printf("Please enter the source vertex: ");
    scanf("%d", &source);
    printf("Please enter the destination vertex: ");
    scanf("%d", &destination);
    printf("Performing DFS...\n");
    DFS(source, destination);
    printf("Performing BFS...\n");
    BFS(source, destination);
    return 0;
}