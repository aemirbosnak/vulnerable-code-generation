//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int m;
int colors[MAX_VERTICES];
int result[MAX_VERTICES];
int k;

void dfs(int v, int c) {
    colors[v] = c;
    result[c]++;

    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] &&!colors[i]) {
            dfs(i, c);
        }
    }
}

int main() {
    srand(time(NULL));

    scanf("%d %d", &n, &m);

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < n; i++) {
        if (!colors[i]) {
            dfs(i, rand() % MAX_COLORS);
        }
    }

    printf("Vertex\tColor\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }

    return 0;
}