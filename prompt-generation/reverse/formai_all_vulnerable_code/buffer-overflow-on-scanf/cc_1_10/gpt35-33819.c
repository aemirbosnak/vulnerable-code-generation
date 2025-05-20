//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int G[MAX][MAX], V[MAX], Color[MAX];
int n, m, K;

void init() {
    int i,j;
    for(i=0;i<MAX;i++) {
        V[i] = Color[i] = 0;
        for(j=0;j<MAX;j++)
            G[i][j] = 0;
    }
}

int isSafe(int v, int c) {
    int i;
    for(i=0;i<n;i++) {
        if(G[v][i] && Color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoring(int v) {
    int c, i;
    if(v == n)
        return 1;
    for(c=1;c<=K;c++) {
        if(isSafe(v, c)) {
            Color[v] = c;
            if(graphColoring(v+1))
                return 1;
            Color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j, a, b;
    scanf("%d %d %d", &n, &m, &K);
    init();
    for(i=0;i<m;i++) {
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    if(graphColoring(0)) {
        printf("Possible solution:\n");
        for(i=0;i<n;i++)
            printf("%d ", Color[i]);
    }
    else
        printf("No solution exists.\n");
    return 0;
}