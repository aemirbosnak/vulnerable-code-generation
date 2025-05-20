//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAXV 100
#define MAXE 100

typedef struct {
    int v;
    int cost;
    int next;
} Edge;

Edge graph[MAXE];
int dist[MAXV];
int n;

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (dist[j]!= INF && graph[j * n + i].cost!= INF) {
                if (dist[j] + graph[j * n + i].cost < dist[i]) {
                    dist[i] = dist[j] + graph[j * n + i].cost;
                }
            }
        }
    }
}

void printSolution(int dest) {
    int v = dest;
    while (v!= -1) {
        printf("%d ", v);
        v = graph[v * n + dest].next;
    }
    printf("\n");
}

int main() {
    int i, j, u, v;
    int start, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the edges and their costs:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i * n + j].cost);
            if (graph[i * n + j].cost!= INF) {
                graph[i * n + j].next = j;
            } else {
                graph[i * n + j].next = -1;
            }
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(start);

    printf("The shortest path from %d to %d is:\n", start, dest);
    printSolution(dest);

    return 0;
}