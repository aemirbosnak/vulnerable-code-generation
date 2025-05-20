//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n, m;
int result;

void init_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void init_color() {
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
}

int dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == -1) {
            int k = 0;
            for (int j = 0; j < MAX_COLORS; j++) {
                if (j!= c && j!= color[i]) {
                    k++;
                }
            }
            if (k == 0) {
                result = 0;
                return 0;
            }
            int w = -1;
            for (int j = 0; j < MAX_COLORS; j++) {
                if (j!= c && j!= color[i] && graph[i][j]) {
                    w = j;
                    break;
                }
            }
            if (dfs(i, w)) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    init_color();
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start_vertex = rand() % n;
    color[start_vertex] = rand() % MAX_COLORS;
    if (dfs(start_vertex, color[start_vertex])) {
        printf("The graph can be colored with %d colors.\n", MAX_COLORS);
    } else {
        printf("The graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}