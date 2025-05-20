//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#define maxN 100

int n, m, x[maxN], count = 0, adj[maxN][maxN];

void coloring(int k)
{
    int color = 1;
    while (1) {
        int ok = 1;
        for (int i = 1; i <= n; i++)
            if (adj[k][i] && x[i] == color) {
                ok = 0;
                break;
            }
        if (ok) break;
        color++;
    }
    x[k] = color;
    if (k == n) {
        count++;
        printf("Solution %d:\n", count);
        for (int i = 1; i <= n; i++) printf("%d ", x[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!x[i]) coloring(i);
    x[k] = 0;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of Edges: ");
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        printf("Enter edge %d between vertices: ", i);
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Solutions:\n");
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    coloring(1);
    if (count == 0)
        printf("No solution found!\n");
    return 0;
}