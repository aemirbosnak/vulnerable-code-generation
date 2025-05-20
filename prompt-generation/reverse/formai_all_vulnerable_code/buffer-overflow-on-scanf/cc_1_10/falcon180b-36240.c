//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000
#define INF 999999

int n, m;
int graph[MAX][MAX];
int color[MAX];
int result[MAX];
int k;

void init() {
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        result[i] = 0;
    }
    k = 1;
}

void printResult() {
    printf("Result:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int isValid(int x) {
    for (int i = 0; i < n; i++) {
        if (color[i] == x) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v) {
    for (int i = 1; i <= n; i++) {
        if (graph[v][i] == 1 && isValid(i)) {
            color[i] = k;
            result[v * n + i] = k;
            backtrack(i);
        }
    }
}

int main() {
    srand(time(NULL));
    int a, b;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init();
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    backtrack(0);
    printResult();
    return 0;
}