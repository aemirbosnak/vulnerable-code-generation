//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 400

int V, E;
int adj_matrix[MAX_V][MAX_V];
int visited[MAX_V];
int parent[MAX_V];
int depth[MAX_V];

void dfs(int v) {
    visited[v] = 1;
    depth[v] = 0;
    for (int i = 0; i < V; i++) {
        if (adj_matrix[v][i] &&!visited[i]) {
            parent[i] = v;
            depth[i] = depth[v] + 1;
            dfs(i);
        }
    }
}

void print_solution(int v) {
    if (v == -1) {
        printf("\n");
        return;
    }
    print_solution(parent[v]);
    printf("%d ", v);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    dfs(0);

    int s = 0;
    int e = 1;

    while (depth[e] < depth[s]) {
        s = e;
        e = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && depth[i] > depth[s]) {
                s = i;
            }
        }
        visited[s] = 1;
    }

    print_solution(s);

    return 0;
}