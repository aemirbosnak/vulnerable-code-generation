//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];

void dijkstra(int graph[V][V], int src)
{
    int u, v, min_dist, i, j;

    for (i = 0; i < V; i++)
        dist[src][i] = graph[src][i];

    for (i = 0; i < V - 1; i++) {
        for (j = 0; j < V - 1; j++) {
            min_dist = INF;
            u = -1;

            for (int k = 0; k < V; k++) {
                if (dist[i][k]!= INF && dist[k][j]!= INF &&
                    dist[i][k] + dist[k][j] < min_dist) {
                    min_dist = dist[i][k] + dist[k][j];
                    u = k;
                }
            }

            if (u!= -1)
                dist[i][j] = min_dist;
        }
    }
}

void print_solution(int dist[], int n)
{
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);
    print_solution(dist, V);

    return 0;
}