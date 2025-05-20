//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k, l, u, v, w, x, y, z, t, count, max_color = 0, color[100], parent[100];
    char graph[100][100];
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 'W';
        }
    }
    for (k = 0; k < m; k++) {
        printf("Enter the edges (u, v, w): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = 'B';
        graph[v][u] = 'B';
    }
    for (l = 0; l < n; l++) {
        color[l] = rand() % 6 + 1;
        parent[l] = -1;
    }
    for (t = 0; t < n; t++) {
        for (u = 0; u < n; u++) {
            if (graph[t][u] == 'B') {
                for (v = 0; v < n; v++) {
                    if (graph[u][v] == 'B') {
                        if (color[t] == color[u] && color[u] == color[v]) {
                            color[t] = ++max_color;
                            parent[t] = u;
                        }
                    }
                }
            }
        }
    }
    printf("\nThe surrealist graph coloring is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 'B') {
                printf("%d ", color[i]);
            } else {
                printf("W ");
            }
        }
        printf("\n");
    }
    return 0;
}