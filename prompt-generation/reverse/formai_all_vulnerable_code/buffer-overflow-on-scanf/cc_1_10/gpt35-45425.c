//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include<stdio.h> 
#include<stdlib.h> 

int V; 
int color[20]; 

void printSolution(int color[]) 
{ 
    printf("The assigned colors to the graph are:\n"); 
    for (int i = 0; i < V; i++) 
        printf("Vertex %d --->  Color %d\n", i, color[i]); 
} 

int isSafe (int v, int graph[20][20], int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if (graph[v][i] && c == color[i]) 
            return 0; 
    return 1; 
} 

int graphColoringUtil(int graph[20][20], int m, int color[], int v) 
{  
    if (v == V) 
        return 1; 

    for (int c = 1; c <= m; c++) 
    { 
        if (isSafe(v, graph, color, c)) 
        { 
           color[v] = c; 
           if (graphColoringUtil(graph, m, color, v+1) == 1) 
             return 1; 
           color[v] = 0; 
        } 
    } 

    return 0; 
} 

int graphColoring(int graph[20][20], int m) 
{ 
    for (int i = 0; i < V; i++) 
       color[i] = 0; 

    if (graphColoringUtil(graph, m, color, 0) == 0) 
    { 
      printf("Solution does not exist\n"); 
      return 0; 
    } 

    printSolution(color); 
    return 1; 
} 

int main() 
{ 
    int graph[20][20], m; 
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nEnter the maximum number of colors to be used: ");
    scanf("%d",&m);
    graphColoring(graph, m); 
    return 0; 
}