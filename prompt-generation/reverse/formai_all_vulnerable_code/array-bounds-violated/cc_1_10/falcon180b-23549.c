//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int V, E;
int graph[100][100];
int color[100];

void initialize() {
    int i, j;
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printSolution(int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void backtrack(int n, int k) {
    int i;
    if(k == V) {
        printSolution(n);
        return;
    }
    for(i = 1; i <= V; i++) {
        if(graph[k][i] == 1 && color[i] == 0) {
            color[i] = 1;
            backtrack(n, i);
            color[i] = 0;
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    int u, v;
    printf("Enter the edges (u v):\n");
    for(i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    initialize();
    int n = 1;
    while(n <= V) {
        int flag = 0;
        for(i = 0; i < V; i++) {
            if(color[i] == 0) {
                color[i] = n;
                flag = 1;
                break;
            }
        }
        if(!flag) {
            n++;
        } else {
            backtrack(n, 0);
            n++;
        }
    }
    return 0;
}