//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define MAX 6
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 9999999

int graph[MAX][MAX];
int n;
int color[MAX];
int parent[MAX];

void init_graph(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int u, int c) {
    color[u] = c;
    parent[u] = -1;
    int v;
    for(v=0; v<n; v++) {
        if(graph[u][v] == 1 && color[v] == WHITE) {
            parent[v] = u;
            dfs(v, 1-c);
        }
        else if(graph[u][v] == 1 && color[v] == GRAY && parent[v]!= u) {
            printf("Back Edge %d %d\n", u, v);
            exit(0);
        }
    }
}

void color_graph(int start) {
    int i;
    for(i=0; i<n; i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }
    dfs(start, 1);
    for(i=0; i<n; i++) {
        if(color[i] == WHITE) {
            printf("No Coloring Exists\n");
            exit(0);
        }
    }
}

int main() {
    int i, j;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    printf("Enter the number of edges: ");
    scanf("%d", &n);
    printf("Enter the edges:\n");
    for(i=0; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    color_graph(0);
    printf("The coloring is:\n");
    for(i=0; i<n; i++) {
        printf("%d ", color[i]+1);
    }
    printf("\n");
    return 0;
}