//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1000
#define INF 1000000

typedef struct {
    int to;
    int cost;
} Edge;

Edge graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int n;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j].to = -1;
            graph[i][j].cost = INF;
        }
    }
}

void addEdge(int u, int v, int w) {
    graph[u][v].to = v;
    graph[u][v].cost = w;
}

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    int q[n];
    int front = 0, rear = -1;
    q[++rear] = start;
    while (front <= rear) {
        int u = q[++front];
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v].to!= -1 && graph[u][v].cost > dist[u] + graph[u][v].cost &&!visited[v]) {
                dist[v] = dist[u] + graph[u][v].cost;
                q[++rear] = v;
            }
        }
    }
}

int main() {
    int i, j, k, u, v, w, start, end;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &k);
    printf("Enter the edges:\n");
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dijkstra(start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);
    printf("The shortest distance from %d to %d is %d\n", start, end, dist[end]);
    return 0;
}