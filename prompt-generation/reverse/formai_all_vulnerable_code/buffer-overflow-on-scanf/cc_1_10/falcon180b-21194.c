//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define MAX_E 200

int V, E;
int adj_matrix[MAX_V][MAX_V];
int visited[MAX_V];
int color[MAX_V];

void init(int v);
int get_color(int v);
void dfs(int v);
void print_solution();

int main() {
    int i, j, u, v;

    scanf("%d %d", &V, &E);

    init(V);

    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = adj_matrix[v][u] = 1;
    }

    for (i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    print_solution();

    return 0;
}

void init(int v) {
    V = v;
    E = 0;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        color[i] = -1;
    }
}

int get_color(int v) {
    int c = 0;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            continue;
        }

        if (adj_matrix[v][i]) {
            c += color[i];
        }
    }

    return c % 3;
}

void dfs(int v) {
    visited[v] = 1;
    color[v] = get_color(v);

    for (int i = 0; i < V; i++) {
        if (adj_matrix[v][i] &&!visited[i]) {
            dfs(i);
        }
    }
}

void print_solution() {
    printf("Vertex\tColor\n");

    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}