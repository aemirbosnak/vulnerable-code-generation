//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 99999

typedef struct {
    int id;
    int cost;
    int next;
} Edge;

Edge graph[MAX_EDGES];
int numEdges = 0;

void addEdge(int u, int v, int cost) {
    graph[numEdges].id = v;
    graph[numEdges].cost = cost;
    graph[numEdges].next = -1;
    numEdges++;
}

void dijkstra(int start, int end) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < numEdges; i++) {
        int u = graph[i].id;
        int v = graph[i].next;
        int cost = graph[i].cost;

        if (dist[u]!= INF && dist[u] + cost < dist[v]) {
            dist[v] = dist[u] + cost;
        }
    }

    int path[MAX_NODES];
    int pathLength = 0;

    int current = end;
    while (current!= -1) {
        path[pathLength++] = current;
        current = visited[current];
    }

    printf("Shortest path: ");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 2, 1);
    addEdge(1, 3, 6);
    addEdge(2, 3, 2);

    dijkstra(0, 3);

    return 0;
}