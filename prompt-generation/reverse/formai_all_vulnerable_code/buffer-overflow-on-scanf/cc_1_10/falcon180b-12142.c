//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

// Graph represented as adjacency matrix
int graph[V][V] = {{0, 4, INF, 8}, {INF, 0, 8, INF}, {INF, INF, 0, 2}, {INF, INF, INF, 0}};

void printSolution(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int src, int dest, int dist[]) {
    int u, v;
    int minDistance = INF, secondMinDistance = INF;
    int minIndex, secondMinIndex;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        minDistance = INF;
        minIndex = -1;

        for (int i = 0; i < V; i++) {
            if (dist[i] <= minDistance && dist[i]!= INF) {
                minDistance = dist[i];
                minIndex = i;
            }
        }

        if (minIndex == -1)
            break;

        for (int j = 0; j < V; j++) {
            if (graph[minIndex][j]!= INF) {
                int newDistance = dist[minIndex] + graph[minIndex][j];

                if (newDistance < dist[j]) {
                    dist[j] = newDistance;
                }
            }
        }
    }

    printf("\nVertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int source, destination;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination, graph);

    return 0;
}