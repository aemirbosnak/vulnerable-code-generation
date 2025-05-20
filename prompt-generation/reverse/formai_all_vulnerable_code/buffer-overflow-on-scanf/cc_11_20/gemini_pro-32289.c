//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define MAX_N 100
#define MAX_M 1000

int n, m;
int adj[MAX_N][MAX_N];
int col[MAX_N];

int main() {
    scanf("%d %d", &n, &m);
    assert(1 <= n && n <= MAX_N);
    assert(1 <= m && m <= MAX_M);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        adj[u][v] = adj[v][u] = 1;
    }

    int max_deg = 0;
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            deg += adj[i][j];
        }
        max_deg = fmax(max_deg, deg);
    }

    int num_colors = (int)ceil(max_deg / 2.0);

    for (int i = 1; i <= n; i++) {
        col[i] = -1;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            cnt++;
            col[i] = cnt;
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] && col[j] == -1) {
                    col[j] = cnt;
                }
            }
        }
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
        printf("%d ", col[i]);
    }
    printf("\n");

    return 0;
}