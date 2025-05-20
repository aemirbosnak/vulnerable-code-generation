//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100 //maximum number of vertices in the graph

int m; //number of colors
int x[MAXV]; //current color assignment for vertex i
int graph[MAXV][MAXV]; //adjacency matrix representation of the graph

//function to check if it is possible to color a vertex v with color c
int promising(int v){
    int i;
    for(i=0;i<MAXV;++i){
        if(graph[v][i] && x[v]==x[i]) //if adjacent vertices have the same color
            return 0;
    }
    return 1;
}

//function to recursively assign colors to vertices
void coloring(int v){
    int c;
    if(v==MAXV){ //if all vertices have been assigned a color
        printf("Coloring found:\n");
        for(int i=0;i<MAXV;++i)
            printf("Vertex %d is assigned color %d\n",i,x[i]);
        exit(0); //exit the program
    }
    for(c=1;c<=m;++c){ //try assigning each color to the current vertex
        x[v]=c;
        if(promising(v)) //if the assignment is promising
            coloring(v+1); //move on to the next vertex
        x[v]=0; //unassign the color
    }
}

int main(){
    printf("Enter the number of colors: ");
    scanf("%d",&m);
    //initialize the adjacency matrix
    for(int i=0;i<MAXV;++i)
        for(int j=0;j<MAXV;++j)
            graph[i][j]=0;
    //add edges to the graph
    graph[0][1]=graph[1][0]=1;
    graph[1][2]=graph[2][1]=1;
    graph[2][3]=graph[3][2]=1;
    graph[3][4]=graph[4][3]=1;
    graph[4][0]=graph[0][4]=1;

    coloring(0); //start the color assignment from vertex 0
    printf("Coloring not possible with %d colors\n",m);
    return 0;
}