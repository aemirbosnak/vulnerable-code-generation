//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

int n; // number of vertices in the graph
int m; // number of edges in the graph
int graph[101][101]; // 2D array to store the graph
int color[101]; // 1D array to store the color of each vertex
int usedColor[101]; // 1D array to store the colors already used

void input() {
    int i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
        color[i] = 0;
        usedColor[i] = 0;
    }
    printf("Enter the edges:\n");
    for (i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

int getUnusedColor() {
    int i;
    for (i = 1; i <= n; i++) { 
        if (!usedColor[i]) {
            usedColor[i] = 1;
            return i;
        }
    }
    return -1;
}

int canColor(int vertex, int c) {
    int i;
    for (i = 1; i <= n; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graphColor(int vertex) {
    if (vertex == n+1) {
        return 1;
    }
    int c;
    for (c = 1; c <= n; c++) {
        if (canColor(vertex, c)) {
            color[vertex] = c;
            int result = graphColor(vertex+1);
            if (result) {
                return 1;
            }
            color[vertex] = 0;
        }
    }
    return 0;
}

void colorGraph() {
    int result = graphColor(1);
    if (!result) {
        printf("The graph cannot be colored with %d colors.\n", n);
    }
    else {
        printf("The graph can be colored with %d colors as follows:\n", n);
        int i;
        for (i = 1; i <= n; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    }
}

int main() {
    input();
    colorGraph();
    return 0;
}