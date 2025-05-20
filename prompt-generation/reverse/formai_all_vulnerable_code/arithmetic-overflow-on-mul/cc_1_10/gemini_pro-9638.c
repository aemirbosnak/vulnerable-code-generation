//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int n, m;
int graph[MAXN][MAXN];
int colors[MAXN];
int best_colors[MAXN];
int best_score;

void input_graph() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        graph[a][b] = graph[b][a] = 1;
    }
}

int calc_score(int *colors) {
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] && colors[i] == colors[j]) {
                score++;
            }
        }
    }
    return score;
}

void dfs(int v, int color) {
    colors[v] = color;
    int score = calc_score(colors);
    if (score <= best_score) {
        if (score < best_score) {
            best_score = score;
            for (int i = 0; i < n; i++) {
                best_colors[i] = colors[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && colors[v] != colors[i]) {
                dfs(i, colors[v]);
            }
        }
    }
    colors[v] = 0;
}

void solve() {
    best_score = n * n;
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
        best_colors[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        dfs(i, i + 1);
    }
}

void output() {
    for (int i = 0; i < n; i++) {
        printf("%d ", best_colors[i]);
    }
    printf("\n");
}

int main() {
    input_graph();
    solve();
    output();
    return 0;
}