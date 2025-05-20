//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000  // Maximum number of nodes in the graph

// Graph structure
struct Graph 
{
    int V;    // Number of nodes in the graph
    int E;    // Number of edges in the graph
    int adj[N][N];    // Adjacency matrix representation of the graph
};

// Create graph
void create_graph(struct Graph *g) 
{
    int i, j, k, v, u;
    g->E = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &g->V);

    for (i = 1; i <= g->V; i++) 
    {
        for (j = 1; j <= g->V; j++) 
        {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    for (i = 1; i <= k; i++) 
    {
        printf("Enter edges (u, v): ");
        scanf("%d%d", &u, &v);

        // Add edges to the adjacency matrix
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;

        g->E++;
    }
}

// Breadth-first search
void BFS(struct Graph *g, int start, int end) 
{
    int queue[N], visited[N], distance[N];
    int front = 0, rear = 0, i, current;

    // Initialize visited and distance array
    for (i = 1; i <= g->V; i++) 
    {
        visited[i] = false;
        distance[i] = -1;
    }

    // Enqueue the starting node
    queue[rear++] = start;

    visited[start] = true;
    distance[start] = 0;

    // Loop until the queue is empty
    while (front != rear) 
    {
        current = queue[front++];
        printf("%d ", current);

        // Enqueue unvisited neighbour nodes
        for (i = 1; i <= g->V; i++) 
        {
            if (g->adj[current][i] == 1 && visited[i] == false) 
            {
                queue[rear++] = i;

                visited[i] = true;
                distance[i] = distance[current] + 1;

                if (i == end)   // If destination node is found, exit
                    break;

            }
        }
    }

    // Print the shortest distance between the start and end nodes
    printf("\nThe shortest distance between the nodes %d and %d is %d\n", start, end, distance[end]);
}

// Main function
int main() 
{
    struct Graph g;

    create_graph(&g);

    int start, end;

    printf("Enter the starting and ending nodes: ");
    scanf("%d%d", &start, &end);

    printf("The BFS traversal starting from the node %d: ", start);
    BFS(&g, start, end);

    return 0;
}