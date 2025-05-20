//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 2000
#define INF 1000000

typedef struct {
    int v;
    int w;
    int next;
} Edge;

Edge graph[MAX_EDGE];
int dist[MAX_VERTEX];
int visited[MAX_VERTEX];
int parent[MAX_VERTEX];

void dijkstra(int start) {
    int i, j, min_dist, u;
    for (i = 0; i < MAX_VERTEX; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for (i = 0; i < MAX_VERTEX - 1; i++) {
        min_dist = INF;
        u = -1;
        for (j = 0; j < MAX_VERTEX; j++) {
            if (dist[j] < min_dist &&!visited[j]) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < MAX_EDGE; j++) {
            if (graph[j].v == u &&!visited[graph[j].w]) {
                if (dist[u] + graph[j].w < dist[graph[j].w]) {
                    dist[graph[j].w] = dist[u] + graph[j].w;
                    parent[graph[j].w] = u;
                }
            }
        }
    }
}

void print_path(int end) {
    int i;
    printf("Path from 0 to %d:\n", end);
    for (i = end; i!= -1; i = parent[i]) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int i, j, n, m, start, end;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (vertex1 vertex2 weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &graph[i].v, &graph[i].w, &graph[i].next);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("Enter ending vertex: ");
    scanf("%d", &end);
    dijkstra(start);
    print_path(end);
    return 0;
}