//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 200
#define MAX_COLOR 100

int V, E, color[MAX_V];
int adj[MAX_V][MAX_V];
int visited[MAX_V];
int queue[MAX_V];
int front, rear;

void enqueue(int v)
{
    if (rear == MAX_V - 1)
        printf("\nQueue is full");
    else
    {
        rear++;
        queue[rear] = v;
    }
}

int dequeue()
{
    int v = queue[front++];
    return v;
}

void bfs(int start)
{
    int u, v;
    enqueue(start);
    visited[start] = 1;
    color[start] = 1;

    while (front <= rear)
    {
        u = dequeue();
        for (v = 0; v < V; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                enqueue(v);
                color[v] = color[u] + 1;
            }
            else if (adj[u][v] == 1 && visited[v] == 1 && color[u] == color[v])
            {
                printf("\nGraph is not properly colored");
                exit(0);
            }
        }
    }
}

int main()
{
    int i, j, u, v;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &V);

    printf("\nEnter the number of edges: ");
    scanf("%d", &E);

    for (i = 0; i < V; i++)
        color[i] = 0;

    printf("\nEnter the edges with their vertices: ");
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (i = 0; i < V; i++)
    {
        if (color[i] == 0)
        {
            bfs(i);
        }
    }

    printf("\nThe vertices are colored as follows: ");
    for (i = 0; i < V; i++)
    {
        printf("%d ", color[i]);
    }

    return 0;
}