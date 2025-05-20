//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

int n, m; // number of vertices and edges
int G[100][100]; // adjacency matrix
int colors[100]; // colors of vertices

// function to check if the current vertex and color combination is feasible
int is_feasible(int v, int c) {
    for(int i=0; i<n; i++) {
        if(G[v][i] && c == colors[i]) {
            return 0;
        }
    }
    return 1;
}

// function to recursively assign colors to vertices
void graph_coloring(int v) {
    if(v == n) { // base case: all vertices are assigned colors
        printf("Colors of vertices:\n");
        for(int i=0; i<n; i++) {
            printf("%d ", colors[i]);
        }
        exit(0);
    } else {
        // try all possible colors for the current vertex
        for(int c=1; c<=m; c++) {
            if(is_feasible(v, c)) {
                colors[v] = c;
                graph_coloring(v+1);
                colors[v] = 0;
            }
        }
    }
}

// main function
int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    
    graph_coloring(0);
    
    printf("Solution not possible!\n");
    return 0;
}