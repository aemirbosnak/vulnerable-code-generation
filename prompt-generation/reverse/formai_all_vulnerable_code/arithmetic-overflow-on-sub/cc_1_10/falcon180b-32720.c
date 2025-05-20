//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 100

int v, e;
int adj_mat[MAX_V][MAX_V];
int dist[MAX_V];
int parent[MAX_V];

void dijkstra(int start) {
    int u, i, j, min_dist;
    for (u = 0; u < v; u++) {
        dist[u] = INF;
        parent[u] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < v - 1; i++) {
        u = -1;
        min_dist = INF;
        for (j = 0; j < v; j++) {
            if (dist[j] < min_dist && adj_mat[j][i]!= 0) {
                min_dist = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        for (j = 0; j < v; j++) {
            if (adj_mat[u][j]!= 0 && dist[u] + adj_mat[u][j] < dist[j]) {
                dist[j] = dist[u] + adj_mat[u][j];
                parent[j] = u;
            }
        }
    }
}

void print_path(int end) {
    if (parent[end] == -1)
        printf("%d", end);
    else {
        print_path(parent[end]);
        printf(" -> %d", end);
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &adj_mat[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &u);
    dijkstra(u);
    printf("The shortest path from vertex %d to vertex %d is: ", u, v - 1);
    print_path(v - 1);
    printf("\n");
    return 0;
}