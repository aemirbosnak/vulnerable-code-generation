//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INFINITY INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES] = {0};
int num_vertices, start_vertex;

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start_vertex, int num_vertices, int distance[])
{
    int i, j, min_dist, next_vertex;

    for (i = 1; i < num_vertices; i++)
        distance[i] = INFINITY;

    distance[start_vertex] = 0;

    for (i = 1; i < num_vertices; i++) 
    {
        min_dist = INFINITY;

        for (j = 1; j < num_vertices; j++) 
        {
            if (!visited[j] && distance[j] <= min_dist) 
            {
                min_dist = distance[j];
                next_vertex = j;
            }
        }

        visited[next_vertex] = 1;

        for (j = 1; j < num_vertices; j++) 
        {
            if (!visited[j] && graph[next_vertex][j]) 
            {
                if (distance[next_vertex] + graph[next_vertex][j] < distance[j]) 
                {
                    distance[j] = distance[next_vertex] + graph[next_vertex][j];
                }
            }
        }
    }
}

int main() 
{
    int i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");

    for (i = 1; i <= num_vertices; i++)
        for (j = 1; j <= num_vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    dijkstra(graph, start_vertex, num_vertices, distance);

    printf("Shortest distance from %d:\n", start_vertex);

    for (i = 1; i <= num_vertices; i++)
    {
        if (distance[i] == INFINITY)
            printf("%d: no path\n", i);
        else
            printf("%d: %d\n", i, distance[i]);
    }

    return 0;
}