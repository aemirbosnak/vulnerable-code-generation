//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 10000
#define MAX_COLOR 10000

int graph[MAX_VERTEX][MAX_VERTEX];

int color[MAX_VERTEX];

int dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < MAX_VERTEX; i++) {
        if (graph[v][i] && color[i] == -1) {
            int new_c = (c + 1) % MAX_COLOR;
            if (!dfs(i, new_c)) {
                return 0;
            }
        } else if (graph[v][i] && color[i]!= -1 && color[i]!= c && color[i]!= (c + 1) % MAX_COLOR) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    srand(time(NULL));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    int res = 0;
    for (int i = 0; i < MAX_COLOR; i++) {
        for (int j = 0; j < v; j++) {
            color[j] = -1;
        }
        res += dfs(0, i);
    }

    printf("Minimum number of colors: %d\n", res);

    return 0;
}