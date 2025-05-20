//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define MAX 20 // Maximum number of vertices in the graph

void graphColoring(int n, int G[][MAX], int m){
    int i, j, k;
    int color[MAX]; // Used to store the color assigned to each vertex
    
    for(i=1; i<=n; i++){
        color[i] = 0; // Initializing all vertices with no color
    }
    
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            for(k=1; k<=n; k++){
                if(G[i][k] && color[k] == j){ // Checking if the adjacent vertex has already been assigned the color
                    break;
                }
            }
            if(k == n+1){ // If no adjacent vertex has the same color, assign this color to the current vertex
                color[i] = j;
                break;
            }
        }
    }
    
    printf("Colors assigned to vertices are: \n");
    for(i=1; i<=n; i++){
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main(){
    int i, j, n, m, G[MAX][MAX];
    
    printf("Enter the number of vertices in the graph (Maximum %d): ", MAX);
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected): \n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &G[i][j]);
        }
    }
    
    printf("Enter the number of colors to be used: ");
    scanf("%d", &m);
    
    graphColoring(n, G, m);
    
    return 0;
}