//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX_V 20

int n, m;
int adj_mat[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];

void init() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                adj_mat[i][j] = 0;
            } else {
                adj_mat[i][j] = INF;
            }
        }
    }
}

void dijkstra(int start) {
    int i, u, v;
    int min_dist = INF;
    int s = start;
    dist[s] = 0;

    for (i = 1; i < n; i++) {
        min_dist = INF;
        u = -1;

        for (v = 0; v < n; v++) {
            if (dist[v] <= min_dist && v!= s) {
                min_dist = dist[v];
                u = v;
            }
        }

        dist[u] = min_dist;
        parent[u] = s;
    }
}

void print_solution(int end) {
    int v = end;
    printf("Vertex\tPath\n");
    while (v!= -1) {
        printf("%d\t", v);
        v = parent[v];
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_mat[i][j]);
        }
    }

    init();
    dijkstra(0);
    print_solution(n - 1);

    return 0;
}