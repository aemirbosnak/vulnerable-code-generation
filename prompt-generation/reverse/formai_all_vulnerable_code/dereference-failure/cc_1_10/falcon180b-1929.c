//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int n;

void createGraph(int graph[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int coloring(int graph[MAX][MAX], int n, int m, int color[MAX]) {
    int i, j, k, l;
    int count = 0;
    for (i = 0; i < n; i++) {
        color[i] = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                for (k = 0; k < m; k++) {
                    if (color[i] == -1 && color[j] == -1) {
                        color[i] = k;
                        color[j] = k;
                        count++;
                        break;
                    } else if (color[i] == -1) {
                        color[i] = k;
                        count++;
                        break;
                    } else if (color[j] == -1) {
                        color[j] = k;
                        count++;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int graph[MAX][MAX];
    int color[MAX];
    int n, m, i, j, k, l, count;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    createGraph(graph, n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the vertices for edge %d: ", i + 1);
        scanf("%d%d", &k, &l);
        addEdge(graph, k, l);
    }

    count = coloring(graph, n, m, color);

    printf("The chromatic number of the graph is %d\n", count);

    return 0;
}