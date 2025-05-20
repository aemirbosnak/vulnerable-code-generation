//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define INF 9999

int graph[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];

void dijkstra(int s) {
    int u, v, i, min, j;
    for (i = 0; i < MAX_V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[s] = 0;
    for (i = 0; i < MAX_V - 1; i++) {
        min = INF;
        u = -1;
        for (j = 0; j < MAX_V; j++) {
            if (dist[j] <= min && graph[j][i]!= 0) {
                min = dist[j];
                u = j;
            }
        }
        dist[i] = min + graph[u][i];
        parent[i] = u;
    }
}

void print_path(int v, int u) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    print_path(parent[v], u);
    printf(" %d", v);
}

int main() {
    int i, j, u, v, n, m, s, t;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the vertices and their edges:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    dijkstra(s);
    printf("Vertex\tDistance\tPath\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i, dist[i]);
        print_path(i, i);
        printf("\n");
    }
    return 0;
}