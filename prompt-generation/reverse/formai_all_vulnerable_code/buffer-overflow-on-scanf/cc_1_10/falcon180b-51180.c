//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int ncolors;
int color[MAX_VERTICES];

int dfs(int v, int c) {
    int i;

    color[v] = c;

    for (i = 0; i < nvertices; i++) {
        if (graph[v][i] && color[i] == -1) {
            if (!dfs(i, c + 1)) {
                return 0;
            }
        } else if (graph[v][i] && color[i]!= c && color[i]!= c + 1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int i, j, k;
    int m;

    printf("Enter the number of vertices: ");
    scanf("%d", &nvertices);

    printf("Enter the number of colors: ");
    scanf("%d", &ncolors);

    printf("Enter the graph:\n");
    for (i = 0; i < nvertices; i++) {
        for (j = 0; j < nvertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (k = 0; k < ncolors; k++) {
        for (i = 0; i < nvertices; i++) {
            color[i] = -1;
        }

        if (dfs(0, k)) {
            printf("Coloring %d:\n", k);
            for (i = 0; i < nvertices; i++) {
                printf("%d ", color[i]);
            }
            printf("\n");
        }
    }

    return 0;
}