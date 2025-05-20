//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>
#define MAX 100

int n, m;
int graph[MAX][MAX], visited[MAX], parent[MAX];
int cost = 0;

void prims_algorithm() {
    int i, j, u, v, min;
    for (i = 1; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    visited[0] = 1;
    for (i = 0; i < n - 1; i++) {
        min = MAX;
        for (j = 0; j < n; j++) {
            if (visited[j]) {
                for (int k = 0; k < n; k++) {
                    if (!visited[k] && graph[j][k]) {
                        if (min > graph[j][k]) {
                            min = graph[j][k];
                            u = j;
                            v = k;
                        }
                    }
                }
            }
        }
        visited[v] = 1;
        cost += graph[u][v];
        parent[v] = u;
    }
}

void print_MST() {
    printf("The MST is as follows:\n");
    for (int i = 1; i < n; i++) {
        printf("%d-%d : %d\n", parent[i], i, graph[i][parent[i]]);
    }
    printf("The total cost is : %d\n", cost);
}

int main() {
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &n, &m);
    printf("Enter the graph matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    prims_algorithm();
    print_MST();
    return 0;
}