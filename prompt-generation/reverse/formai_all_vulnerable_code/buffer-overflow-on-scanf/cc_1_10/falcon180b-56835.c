//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define MAX_E 200
#define INF 0x3f3f3f3f

int n, m;
int graph[MAX_V][MAX_V];
int color[MAX_V];
int parent[MAX_V];
int visited[MAX_V];
int min_color;
int max_color;

void init() {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        color[i] = rand() % (max_color - min_color + 1) + min_color;
        parent[i] = -1;
    }
}

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] &&!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init();

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int num_colors = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            num_colors++;
        }
    }

    printf("The minimum number of colors needed is: %d\n", num_colors);

    return 0;
}