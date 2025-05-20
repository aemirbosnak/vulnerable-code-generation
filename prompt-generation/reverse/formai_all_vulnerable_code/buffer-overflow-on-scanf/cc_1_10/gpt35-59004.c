//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int adj[MAX][MAX];      //Adjacency Matrix
int color[MAX];         //Valid Colors Array
int n;                  //Number of vertices

//Function to check if the given color is valid for the current vertex
int isValid(int v, int c) {
    for(int i=0; i<n; i++) {
        if(adj[v][i] && c==color[i])
            return 0;
    }
    return 1;
}

//Recursive function to perform graph coloring
int graphColoring(int v) {
    if(v==n)    //All vertices have been colored
        return 1;
    for(int i=1; i<=n; i++) {   //Iterating over all colors
        if(isValid(v,i)) {      //Checking if the color is valid for the current vertex
            color[v] = i;       //Assigning color to the current vertex
            if(graphColoring(v+1))  //Recursively coloring next vertices
                return 1;
            color[v] = 0;       //If no valid color found, resetting the color and trying with next color
        }
    }
    return 0;
}

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    //Inputting the adjacency matrix
    printf("Enter the Adjacency Matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        color[i] = 0;           //Initializing all vertices with no color
    }

    if(graphColoring(0)) {      //Performing graph coloring starting with first vertex
        printf("The vertices can be colored as:\n");
        for(int i=0; i<n; i++) {
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    }
    else {
        printf("Coloring not possible!\n");    //If no valid color found
    }
}