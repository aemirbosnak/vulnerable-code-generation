//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int V; // number of vertices

void readGraph()
{
    int i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix of the graph:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int isSafe(int v, int c)
{
    int i;
    
    for(i = 0; i < V; i++) {
        if(graph[v][i] && c == color[i]) { // if adjacent vertex has same color
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(int v)
{
    int c;
    
    if(v == V) { // All vertices are colored
        return 1;
    }
    
    for(c = 1; c <= V; c++) { // Try different colors
        if(isSafe(v, c)) {
            color[v] = c;
            
            if(graphColoringUtil(v+1)) { // Recursively color rest of the vertices
                return 1;
            }
            
            color[v] = 0;
        }
    }
    return 0;
}

void graphColoring()
{
    int i;
    if(graphColoringUtil(0)) {
        printf("Solution Exists!\nThe colors of the vertices: ");
        for(i = 0; i < V; i++) {
            printf("%d ", color[i]);
        }
    } else {
        printf("Solution does not exist!");
    }
}

int main()
{
    readGraph();
    
    graphColoring();
    
    return 0;
}