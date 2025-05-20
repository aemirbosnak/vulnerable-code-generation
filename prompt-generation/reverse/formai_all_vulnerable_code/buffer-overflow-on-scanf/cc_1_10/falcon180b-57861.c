//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 1000
#define MAX_E 10000
#define INF 0x3f3f3f3f

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge edge[MAX_E];
int adj[MAX_V];
int dist[MAX_V];
int parent[MAX_V];
int n, m, start, end;

void init() {
    for (int i = 0; i < MAX_V; i++) {
        adj[i] = -1;
        dist[i] = INF;
        parent[i] = -1;
    }
}

void add_edge(int u, int v, int c) {
    edge[m].to = v;
    edge[m].cost = c;
    edge[m].next = adj[u];
    adj[u] = m++;
}

void dijkstra(int s) {
    int u, v;
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = adj[j]; k!= -1; k = edge[k].next) {
                u = j;
                v = edge[k].to;
                if (dist[u]!= INF && dist[u] + edge[k].cost < dist[v]) {
                    dist[v] = dist[u] + edge[k].cost;
                    parent[v] = u;
                }
            }
        }
    }
}

void print_path(int v) {
    if (v == -1 || v == start)
        return;
    print_path(parent[v]);
    printf("%d ", v);
}

int main() {
    srand(time(0));
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    scanf("%d%d", &start, &end);
    dijkstra(start);
    printf("Shortest Path: ");
    print_path(end);
    printf("\nTotal Cost: %d\n", dist[end]);
    return 0;
}