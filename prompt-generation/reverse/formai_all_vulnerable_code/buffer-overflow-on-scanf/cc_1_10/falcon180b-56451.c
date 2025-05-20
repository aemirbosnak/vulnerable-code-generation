//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLOR 6

int n;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int count[MAX_COLOR];

int search(int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[x][i] == 1) {
            return i;
        }
    }
    return -1;
}

int is_safe(int v, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (color[i] == c) {
                return 0;
            }
        }
    }
    return 1;
}

void color_graph(int v) {
    int i, c;
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (color[i] == -1) {
                color[i] = 1;
                count[1]++;
            } else {
                c = color[i];
                if (c > 1) {
                    count[c]--;
                }
                color[i] = -1;
            }
        }
    }
}

int main() {
    int i, j, k;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &k);

    printf("Enter the edges:\n");
    for (i = 0; i < k; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int m = 0;
    for (i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = m;
            m++;
            color_graph(i);
        }
    }

    printf("The minimum number of colors required is: %d\n", m);

    return 0;
}