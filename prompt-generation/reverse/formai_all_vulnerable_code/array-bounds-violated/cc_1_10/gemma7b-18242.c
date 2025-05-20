//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], color[MAX], degree[MAX], n, m;

void dfs(int i) {
    for (int j = 0; j < n; j++) {
        if (graph[i][j] && color[j] == -1) {
            color[j] = color[i];
            dfs(j);
        }
    }
}

int main() {
    scanf("Enter the number of nodes and edges: ", &n);
    scanf("Enter the number of edges: ", &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("Enter the two nodes connected by an edge: ", &u);
        scanf("Enter the two nodes connected by an edge: ", &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            color[i] = 0;
        } else {
            color[i] = -1;
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        printf("The color of node %d is %d\n", i, color[i]);
    }

    return 0;
}