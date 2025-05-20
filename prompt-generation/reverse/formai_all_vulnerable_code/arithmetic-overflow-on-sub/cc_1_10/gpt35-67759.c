//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define infinity as a very large number
#define INF 999999999

// Define a function to read in the graph from an input file
void read_graph(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    FILE* input = fopen("graph.txt", "r");   // Replace with your own file name
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            fscanf(input, "%d", &graph[i][j]);
        }
    }
    fclose(input);
}

// Define a function to implement Dijkstra's Algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start_vertex, int num_vertices) {
    int dist[MAX_VERTICES]; // Track the shortest distance from start to each vertex
    bool visited[MAX_VERTICES] = { false };  // Track which vertices have been visited
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INF;  // Set initial distances to infinity
    }
    dist[start_vertex] = 0;  // Set distance to starting vertex to 0
    
    // Loop through all vertices to find the shortest path to each
    for (int i = 0; i < num_vertices - 1; i++) {
        int min_dist = INF, current_vertex;
        
        // Find the vertex with the minimum distance that has not been visited
        for (int j = 0; j < num_vertices; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                current_vertex = j;
            }
        }
        
        // Mark current vertex as visited
        visited[current_vertex] = true;
        
        // Update distances to neighboring vertices
        for (int k = 0; k < num_vertices; k++) {
            if (!visited[k] && graph[current_vertex][k] != 0 && dist[current_vertex] + graph[current_vertex][k] < dist[k]) {
                dist[k] = dist[current_vertex] + graph[current_vertex][k];
            }
        }
    }
    
    // Print the shortest distances from starting vertex to each vertex
    for (int i = 0; i < num_vertices; i++) {
        printf("Shortest distance from Vertex %d to Vertex %d is %d\n", start_vertex, i, dist[i]);
    }
}

int main() {
    int num_vertices, start_vertex;
    int graph[MAX_VERTICES][MAX_VERTICES];
    
    // Read in graph from input file
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    read_graph(graph, num_vertices);
    
    // Get starting vertex from user
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);
    
    // Call Dijkstra's Algorithm to find the shortest path
    dijkstra(graph, start_vertex, num_vertices);
    
    return 0;
}