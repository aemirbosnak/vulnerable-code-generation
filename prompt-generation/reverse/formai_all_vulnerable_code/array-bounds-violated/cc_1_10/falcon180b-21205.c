//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 9999

int adj_matrix[MAX_VERTEX][MAX_VERTEX];

void add_edge(int u, int v, int cost) {
    adj_matrix[u][v] = cost;
    adj_matrix[v][u] = cost;
}

void floyd_warshall(int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj_matrix[i][k]!= INF && adj_matrix[k][j]!= INF && adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j]) {
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m, i, j, u, v, cost;
    char graph[MAX_VERTEX][MAX_VERTEX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v cost): ");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        add_edge(u, v, cost);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    floyd_warshall(n);

    printf("The shortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj_matrix[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", adj_matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}