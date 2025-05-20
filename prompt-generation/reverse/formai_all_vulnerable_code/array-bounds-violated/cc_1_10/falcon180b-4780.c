//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 999999

int n, m;
int graph[MAX_NODES][MAX_NODES];
int cost[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];
int visited[MAX_NODES];

void a_star(int start, int end) {
    int u, v, k, min_cost;
    int i, j;

    for (i = 0; i < n; i++) {
        cost[start][i] = graph[start][i];
        parent[i] = -1;
    }

    cost[start][start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_cost = INF;
        for (u = 0; u < n; u++) {
            if (!visited[u] && cost[start][u] + cost[u][end] < min_cost) {
                min_cost = cost[start][u] + cost[u][end];
                k = u;
            }
        }

        visited[k] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && cost[start][v] + cost[v][k] < cost[start][k]) {
                cost[start][v] = cost[start][k];
                parent[v] = k;
            }
        }
    }

    printf("\nPath from %d to %d:\n", start, end);
    k = end;
    while (k!= -1) {
        printf("%d ", k);
        k = parent[k];
    }
    printf("\n");
}

int main() {
    int i, j, u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the graph:\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &graph[u][v]);
        graph[v][u] = graph[u][v];
    }

    printf("Enter the costs:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int start, end;
    printf("Enter the start node: ");
    scanf("%d", &start);

    printf("Enter the end node: ");
    scanf("%d", &end);

    a_star(start, end);

    return 0;
}