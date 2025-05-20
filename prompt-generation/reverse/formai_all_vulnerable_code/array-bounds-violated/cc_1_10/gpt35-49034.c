//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Graph Coloring Problem using Greedy Algorithm */

/* colors array stores the color assigned to each vertex */
int colors[50];

/* number of vertices and edges */
int V, E;

/* function to check if it is safe to color a vertex with a particular color */
bool isSafe(int v, int graph[V][V], int c) {
    for(int i=0; i<V; i++) {
        if(graph[v][i] == 1 && colors[i] == c) {
            return false;
        }
    }
    return true;
}

/* function to color the vertices */
bool graphColoring(int graph[V][V], int m, int v) {
    if(v == V) {
        return true;
    }
    for(int c=1; c<=m; c++) {
        if(isSafe(v, graph, c)) {
            colors[v] = c;
            if(graphColoring(graph, m, v+1) == true) {
                return true;
            }
            colors[v] = 0;
        }
    }
    return false;
}

int main() {

    int graph[50][50];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    /* initializing the graph */
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            graph[i][j] = 0;
        }
    }

    /* taking input for the graph */
    printf("Enter the edges: \n");
    for(int i=0; i<E; i++) {
        int u, v;
        printf("Edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    /* color the vertices */
    printf("\nColoring of vertices using Greedy Algorithm: ");

    for(int i=0; i<V; i++) {
        int c = 1;
        while(!isSafe(i, graph, c)) {
            c++;
        }
        colors[i] = c;
    }

    for(int i=0; i<V; i++) {
        printf("\nVertex %d: Color %d", i, colors[i]);
    }

    /* resetting the colors array */
    for(int i=0; i<V; i++) {
        colors[i] = 0;
    }

    /* color the vertices using graphColoring function */
    bool res = false;
    for(int i=1; i<=V; i++) {
        res = graphColoring(graph, i, 0);
        if(res == true) {
            printf("\n\nColoring of vertices using Graph Coloring Problem: ");
            for(int j=0; j<V; j++) {
                printf("\nVertex %d: Color %d", j, colors[j]);
            }
            break;
        }
        /* resetting the colors array */
        for(int j=0; j<V; j++) {
            colors[j] = 0;
        }
    }
    if(res == false) {
        printf("\n\nGraph cannot be colored using %d colors.", V);
    }

    return 0;
}