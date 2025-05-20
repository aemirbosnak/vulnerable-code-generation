//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

int adj_matrix[ROW][COL];
int visited[ROW];
int queue[ROW];
int front = -1, rear = -1;

void bfs(int start, int end)
{
    int i, vertex;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear)
    {
        vertex = queue[++front];

        printf("%d ", vertex);

        if (vertex == end)
        {
            return;
        }

        for (i = 0; i < COL; i++)
        {
            if (adj_matrix[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int start_vertex, end_vertex, i, j, edgeWeight, numberOfEdges, u, v;

    printf("Enter the number of edges: ");
    scanf("%d", &numberOfEdges);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    for (i = 0; i < numberOfEdges; i++)
    {
        printf("Enter U and V of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        printf("Enter Edge Weight: ");
        scanf("%d", &edgeWeight);

        adj_matrix[u][v] = edgeWeight;
        adj_matrix[v][u] = edgeWeight;
    }

    printf("\nEnter the start vertex: ");
    scanf("%d", &start_vertex);

    printf("\nEnter the end vertex: ");
    scanf("%d", &end_vertex);

    bfs(start_vertex, end_vertex);

    return 0;
}