//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

int n, m, s, t, u, v, w, i, j;
int dist[MAX_NODES];
int parent[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];

void dijkstra(int start) {
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (adj_matrix[j][i]!= INF && dist[j] > dist[i] + adj_matrix[j][i]) {
                dist[i] = dist[j] + adj_matrix[j][i];
                parent[i] = j;
            }
        }
    }
}

void print_path(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
    } else {
        int k = end;
        while (k!= -1) {
            printf("%d ", k);
            k = parent[k];
        }
        printf("\n");
    }
}

int main() {
    int i, j, k;
    int start, end;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the start node: ");
    scanf("%d", &start);

    printf("Enter the end node: ");
    scanf("%d", &end);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj_matrix[i][j] = INF;
        }
    }

    printf("Enter the edges (node1 node2 weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    dijkstra(start);
    print_path(end);

    return 0;
}