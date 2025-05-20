//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include<stdio.h>

#define MAXVERT 50  //maximum number of vertices 
#define MAXCOL 4   //maximum number of colors

int graph[MAXVERT][MAXVERT], color[MAXVERT];
int V, E;

/*
 * Function to check if the current color  
 * is safe for the given vertex
 */
int isSafe(int v, int col)
{
    for(int i=0; i<V; i++){
        if(graph[v][i] && col==color[i]){
            return 0; //if adjacent vertex has same color
        }
    }
    return 1; //if color is safe
}

/*
 * Function to implement graph coloring
 */
int graphColoring(int v)
{
    //if all vertices are colored
    if(v==V){
        return 1;
    }

    for(int col=1; col<=MAXCOL; col++){
        //check if the given color is safe for vertex 
        if(isSafe(v,col)){
            color[v] = col; //assign color to vertex

            //recursively color the remaining vertices
            if(graphColoring(v+1)==1){
                return 1;
            }

            //if the color is not safe, backtrack
            color[v] = 0;  
        }
    }
    //if no color can be assigned to the vertex
    return 0;
}

/*
 * Main function to test the program 
 */
int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    //input the edges of the graph
    for(int i=0; i<E; i++){
        int u,v;
        printf("Enter edge %d (u,v): ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    //solve the problem
    if(graphColoring(0)==1){
        printf("Graph can be colored using %d colors.\n", MAXCOL);
        //print the colors of vertices
        printf("The coloring of the vertices is: ");
        for(int i=0; i<V; i++){
            printf("%d ", color[i]);
        }
    }
    else{
        printf("Graph cannot be colored using %d colors.\n", MAXCOL);
    }

    return 0;
}