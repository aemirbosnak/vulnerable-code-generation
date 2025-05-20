//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EDGES 100000
#define MAX_V 1000
#define INF 0x3f3f3f3f

typedef struct {
    int v;
    int cost;
    int next;
} Edge;

Edge graph[MAX_EDGES];
int dist[MAX_V];
int n, m;

void add_edge(int u, int v, int c) {
    graph[m].v = v;
    graph[m].cost = c;
    graph[m].next = dist[u];
    dist[u] = m++;
}

void dijkstra(int start) {
    int i, j, k, u, v;
    int min_dist = INF, count = 0;

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        for (j = 0; j < n; j++) {
            if (dist[j] <= min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }

        for (k = dist[u]; k!= INF; k = graph[k].next) {
            v = graph[k].v;
            if (dist[u] + graph[k].cost < dist[v])
                dist[v] = dist[u] + graph[k].cost;
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w, c, s, t;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges with their weights:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &s);

    dijkstra(s);

    return 0;
}