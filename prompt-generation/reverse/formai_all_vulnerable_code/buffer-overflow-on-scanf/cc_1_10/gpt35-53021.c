//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
/*
* Title: The Adventure of the Pathfinding Algorithm
* Author: Sherlock Holmes (with some help from Dr. Watson)
* Date: January 1, 1900
*
* Description: This program solves a pathfinding problem using Dijkstra's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the solution array
void printSolution(int dist[], int n)
{
    printf("\nPathfinding Results from Start Vertex:\n\n");

    for (int i = 0; i < V; i++)
        printf("Vertex %d \t Distance: %d\n", i, dist[i]);
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

    int sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the solution
    printSolution(dist, V);
}

// Driver program to test above function
int main()
{
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };

    // Pathfinding starting vertices for Dr. Watson's investigation
    int src;
    printf("\nThe investigation has begun! Enter a starting vertex from 0 to %d: ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}