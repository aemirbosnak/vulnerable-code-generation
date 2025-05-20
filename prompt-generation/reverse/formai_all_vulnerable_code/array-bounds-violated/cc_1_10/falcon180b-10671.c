//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define N 10

int dist[N][N];
int path[N][N];
int n, start, end;

void init() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = INF;
            path[i][j] = -1;
        }
    }
}

void a_star(int start, int end) {
    int i, j, u, v;
    int open[N], closed[N];
    int open_size = 0, closed_size = 0;
    int g_score[N], f_score[N], parent[N];

    for (i = 0; i < n; i++) {
        g_score[i] = dist[start][i];
        f_score[i] = g_score[i] + heuristic(start, i);
        path[start][i] = -1;
    }

    open[0] = start;
    open_size = 1;

    while (open_size > 0) {
        int min_f_score = INF;
        int u = -1;

        for (i = 0; i < open_size; i++) {
            if (f_score[open[i]] < min_f_score) {
                min_f_score = f_score[open[i]];
                u = open[i];
            }
        }

        if (u == end) {
            break;
        }

        closed[closed_size++] = u;
        open[--open_size] = u;

        for (v = 0; v < n; v++) {
            if (g_score[u] + dist[u][v] < g_score[v]) {
                g_score[v] = g_score[u] + dist[u][v];
                f_score[v] = g_score[v] + heuristic(end, v);
                path[u][v] = parent[v] = u;
            }
        }
    }

    printf("Path from %d to %d:\n", start, end);
    for (i = end; i!= -1; i = parent[i]) {
        printf("%d ", i);
    }
    printf("\n");
}

int heuristic(int a, int b) {
    int dx = abs(a / N - b / N);
    int dy = abs(a % N - b % N);
    return dx + dy;
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the start node: ");
    scanf("%d", &start);

    printf("Enter the end node: ");
    scanf("%d", &end);

    init();

    a_star(start, end);

    return 0;
}