//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 9999
#define V 8

int adj[V][V] = { { 0, 4, INF, 8 }, { INF, 0, 8, INF }, { INF, INF, 0, 1 }, { INF, INF, INF, 0 } };
int dist[V];
int parent[V];
int visited[V];

void dijkstra(int start) {
    int u, v, i, min;
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < V - 1; i++) {
        min = INF;
        u = -1;
        for (int j = 0; j < V; j++) {
            if (dist[j] <= min &&!visited[j]) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] && dist[u]!= INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int start, end;
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    printf("Enter the end vertex: ");
    scanf("%d", &end);
    dijkstra(start);
    printf("\nPath from %d to %d: ", start, end);
    if (parent[end] == -1) {
        printf("No path found.\n");
    } else {
        int v = end;
        while (v!= -1) {
            printf("%d ", v);
            v = parent[v];
        }
    }
    return 0;
}