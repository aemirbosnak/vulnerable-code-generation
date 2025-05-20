//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 9999

int dist[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start, int end) {
    int i, j, k, min;

    for (i = 0; i < MAX_NODES; i++) {
        dist[start][i] = INF;
        visited[i] = 0;
    }

    dist[start][start] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        for (j = 0; j < MAX_NODES - 1; j++) {
            if (visited[j] == 0 && dist[start][j]!= INF) {
                for (k = 0; k < MAX_NODES - 1; k++) {
                    if (dist[start][k]!= INF && dist[start][k] + dist[j][k] < dist[start][j]) {
                        dist[start][j] = dist[start][k] + dist[j][k];
                    }
                }
            }
        }
    }

    printf("\nShortest distance from node %d to node %d is %d\n", start, end, dist[start][end]);
}

int main() {
    int n, i, j, start, end;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the edges and their weights:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i!= j) {
                printf("Node %d -> Node %d (%d): ", i, j, INF);
                scanf("%d", &dist[i][j]);
            }
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    dijkstra(start, end);

    return 0;
}