//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTEX 100

int n; //number of vertices
int m; //number of edges
int graph[MAX_VERTEX][MAX_VERTEX]; //adjacency matrix for storing the graph
int color[MAX_VERTEX]; //array for storing the color of each vertex
bool available[MAX_VERTEX]; //array for checking the availability of each color

bool isSafe(int v, int c) {
    for(int i = 0; i < n; i++) {
        if(graph[v][i] && color[i] == c) { //if vertex v is adjacent to vertex i and vertex i has color c
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v) {
    if(v == n) { //all vertices were colored successfully
        return true;
    }
    for(int c = 1; c <= m; c++) { //try colors sequentially
        if(isSafe(v, c)) {
            color[v] = c; //assign this color to vertex v
            if(graphColoringUtil(v + 1)) { //recursive call to color the next vertex
                return true; //if all vertices are successfully colored then return true
            }
            color[v] = 0; //backtracking
        }
    }
    return false; //if no color can be assigned to vertex v then return false
}

bool graphColoring() {
    for(int i = 0; i < n; i++) {
        color[i] = 0; //initialize color of all vertices to 0 (means no color is assigned yet)
    }
    if(!graphColoringUtil(0)) { //try to color vertex 0 first
        return false; //if vertex 0 cannot be colored then this graph cannot be colored with m colors
    }
    return true; //if all vertices are successfully colored then return true
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    printf("Enter the adjacency matrix of the graph:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if(graphColoring()) {
        printf("This graph can be colored with %d colors.\n", m);
        for(int i = 0; i < n; i++) {
            printf("Color of vertex %d: %d\n", i, color[i]);
        }
    } else {
        printf("This graph cannot be colored with %d colors.\n", m);
    }
    return 0;
}