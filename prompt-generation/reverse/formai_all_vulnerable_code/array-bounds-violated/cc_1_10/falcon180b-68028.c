//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX][MAX];
int n, m;
int color[MAX];

void dfs(int v) {
    color[v] = GRAY;
    for (int u = 0; u < n; u++) {
        if (graph[v][u] == 1 && color[u] == WHITE) {
            dfs(u);
        }
    }
    color[v] = BLACK;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges: \n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == WHITE) {
            dfs(i);
            count++;
        }
    }

    if (count == n) {
        printf("The graph can be colored.\n");
    } else {
        printf("The graph cannot be colored.\n");
    }

    return 0;
}