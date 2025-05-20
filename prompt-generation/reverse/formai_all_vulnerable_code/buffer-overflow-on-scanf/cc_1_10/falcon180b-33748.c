//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int v;
    int w;
    int next;
} edge;

edge graph[MAX_EDGES];
int dist[MAX_NODES];
int visited[MAX_NODES];
int n;

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (dist[j] > dist[i] + graph[j].w) {
                dist[j] = dist[i] + graph[j].w;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter edges with their weights:\n");
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].v = v;
        graph[i].w = w;
        graph[i].next = -1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n - 1; j++) {
            if (graph[i].v == graph[j].v && graph[i].w > graph[j].w) {
                graph[i].next = j;
                break;
            }
        }
    }
    int source;
    printf("Enter source node: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("Shortest distances from node %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i]!= INF) {
            printf("%d -> %d : %d\n", source, i, dist[i]);
        }
    }
    return 0;
}