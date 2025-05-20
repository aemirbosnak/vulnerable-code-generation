//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTEX 50
#define MAX_COLOR 7

int vertex_num;
int edge_num;
int **graph;
int *color;

int dfs(int v, int c) {
    int i;
    color[v] = c;
    for (i = 0; i < vertex_num; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            if (dfs(i, c + 1) == 0) {
                return 0;
            }
        }
        else if (graph[v][i] == 1 && color[i]!= -1 && color[i]!= c && color[i]!= c + 1) {
            return 0;
        }
    }
    return 1;
}

int backtrack(int v, int c) {
    int i;
    color[v] = c;
    for (i = 0; i < vertex_num; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            if (backtrack(i, c + 1) == 0) {
                return 0;
            }
        }
        else if (graph[v][i] == 1 && color[i]!= -1 && color[i]!= c && color[i]!= c + 1) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, j;
    time_t start, end;
    start = clock();

    for (i = 0; i < vertex_num; i++) {
        color[i] = -1;
    }

    for (i = 0; i < vertex_num; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (dfs(i, 0) == 0) {
                printf("Graph cannot be colored with %d colors\n", MAX_COLOR);
                exit(0);
            }
        }
    }

    end = clock();
    printf("Time taken to color the graph: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    int i, j, c;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertex_num);

    graph = (int **)malloc(vertex_num * sizeof(int *));
    for (i = 0; i < vertex_num; i++) {
        graph[i] = (int *)malloc(vertex_num * sizeof(int));
        for (j = 0; j < vertex_num; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges of the graph:\n");
    for (i = 0; i < vertex_num; i++) {
        printf("Enter the edges for vertex %d:\n", i);
        for (j = 0; j < vertex_num; j++) {
            if (graph[i][j] == 0) {
                printf("Enter 1 to connect vertex %d and %d, 0 otherwise: ", i, j);
                scanf("%d", &c);
                if (c == 1) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
    }

    color_graph();

    return 0;
}