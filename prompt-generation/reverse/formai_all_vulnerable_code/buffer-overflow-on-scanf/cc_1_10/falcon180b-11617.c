//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 500
#define INF INT_MAX

typedef struct {
    int v;
    int cost;
    int prev;
} Edge;

Edge min_cost[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];
int n;

void init(int v) {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) {
                min_cost[i][j].cost = 0;
            } else {
                min_cost[i][j].cost = INF;
            }
        }
    }
}

void add_edge(int u, int v, int cost) {
    min_cost[u][v].cost = cost;
    min_cost[v][u].cost = cost;
}

void dijkstra(int start) {
    int u, v;
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(dist[j]!= INF && dist[j] + min_cost[j][k].cost < dist[k]) {
                    dist[k] = dist[j] + min_cost[j][k].cost;
                    parent[k] = j;
                }
            }
        }
    }
}

void print_path(int v) {
    if(parent[v] == -1) {
        printf("%d", v);
        return;
    }
    print_path(parent[v]);
    printf(" -> %d", v);
}

int main() {
    int m, u, v, c;
    scanf("%d %d", &n, &m);
    init(n);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        add_edge(u, v, c);
    }
    int start, end;
    scanf("%d %d", &start, &end);
    dijkstra(start);
    printf("Shortest path from %d to %d: ", start, end);
    print_path(end);
    printf("\n");
    return 0;
}