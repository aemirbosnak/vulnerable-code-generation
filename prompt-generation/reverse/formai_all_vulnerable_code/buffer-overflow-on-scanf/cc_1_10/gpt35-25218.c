//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 100
int color[MAX_VERTEX];

/*Function to check if two adjacent vertices have same color*/
int is_safe(int graph[MAX_VERTEX][MAX_VERTEX], int vertex, int c, int V) {
    int i;
    for(i=0;i<V;i++){
        if(graph[vertex][i] && c==color[i])
            return 0; //Since i in adjacent to vertex and has same color c
    }
    return 1;
}

/*Function to color the vertices of graph*/
void color_graph(int graph[MAX_VERTEX][MAX_VERTEX], int vertex, int V, int m) {
    int c,i;
    if(vertex==V) {
        printf("\nThe required coloring scheme is: ");
        for(i=0;i<V;i++)
            printf("%d ",color[i]+1); //Printing colors starting from 1
        printf("\n");
    }
    else {
        /*Trying out all possible colors for vertex*/
        for(c=0;c<m;c++) {
            if(is_safe(graph,vertex,c,V)) {
                color[vertex]=c; //Assigning color c to vertex
                color_graph(graph,vertex+1,V,m);
                color[vertex]=-1; //Backtracking
            }
        }
    }
}

/*Main Function*/
int main(int argc, char **argv){
    int graph[MAX_VERTEX][MAX_VERTEX],V,m,i,j;
    printf("\n*********************************************\n");
    printf("GRAPH COLORING PROBLEM\n");
    printf("*********************************************\n\n");
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&V);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++) {
            scanf("%d",&graph[i][j]);
        }
        color[i]=-1;
    }
    printf("\nEnter the number of colors available: ");
    scanf("%d",&m);
    if(m<V) {
        printf("\nGraph can be colored by using %d colors\n",m);
        color_graph(graph,0,V,m);
    }
    else {
        printf("\nNumber of colors should be less than or equal to number of vertices in the graph\n");
    }
    return 0;
}