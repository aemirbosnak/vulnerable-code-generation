//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES], n;
int m; // number of colors

void init_graph() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (j = 1; j <= n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, k, x, y;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph();

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    for (i = 1; i <= k; i++) {
        printf("Enter an edge (u, v): ");
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Coloring the graph...\n");

    int color[n+1];

    for (i = 1; i <= n; i++) {
        color[i] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            int ok = 1;
            for (k = 1; k <= n; k++) {
                if (graph[i][k] && color[k] == j) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                color[i] = j;
                break;
            }
        }
    }

    printf("Graph coloring complete!\n");

    printf("Vertex colors:\n");
    for (i = 1; i <= n; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }

    return 0;
}