//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999999

int n, m, s, t, u, v, w, i, j, k, count = 0;
int dist[MAX_NODES], parent[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];

void dijkstra(int start_vertex) {
    int visited[MAX_NODES] = {0};
    int min_dist[MAX_NODES] = {INF};

    dist[start_vertex] = 0;

    for (i = 0; i < n - 1; i++) {
        int min_distance = INF, u = -1;

        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] <= min_distance) {
                min_distance = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (k = 0; k < n; k++) {
            if (adj_matrix[u][k] && visited[k] == 0 && dist[u]!= INF &&
                dist[u] + adj_matrix[u][k] < dist[k]) {
                dist[k] = dist[u] + adj_matrix[u][k];
                parent[k] = u;
            }
        }
    }
}

void print_solution(int dest) {
    if (parent[dest] == -1)
        printf("No path found from source to destination\n");
    else {
        printf("Path from source to destination:\n");
        int v = dest;
        while (v!= -1) {
            printf("%d ", v);
            v = parent[v];
        }
    }
}

int main() {
    int i, j, weight;
    char ch;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj_matrix[i][j] = INF;

    printf("Enter the edges and their weights:\n");

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        adj_matrix[u][v] = weight;
        adj_matrix[v][u] = weight;
    }

    printf("Enter the source and destination nodes: ");
    scanf("%d %d", &s, &t);

    dijkstra(s);
    print_solution(t);

    return 0;
}