//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_COLOR 6

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];
int n, m;

void init(int v, int e) {
    n = v;
    m = e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int color_graph() {
    int i, j, k, c;
    int count = 0;

    for (i = 0; i < n; i++) {
        color[i] = 1;
    }

    do {
        count++;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    for (k = 0; k < MAX_COLOR; k++) {
                        if (color[i]!= k && color[j]!= k) {
                            color[i] = k;
                            color[j] = k;
                            break;
                        }
                    }
                }
            }
        }
    } while (count < MAX_COLOR * n);

    return count;
}

int main() {
    int v, e;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    init(v, e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int result = color_graph();

    printf("The minimum number of colors required is: %d\n", result);

    return 0;
}