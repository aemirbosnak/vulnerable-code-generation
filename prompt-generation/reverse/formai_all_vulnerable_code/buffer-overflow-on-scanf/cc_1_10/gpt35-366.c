//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int color[MAX_VERTICES];

void printSolution(){
    printf("Vertex\tColor\n");
    for(int i=0; i<numVertices; i++){
        printf("%d\t%d\n", i, color[i]);
    }
}

bool isSafe(int v, int c){
    for(int i=0; i<numVertices; i++){
        if(graph[v][i] && c==color[i]){
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int numColours, int v){
    if(v==numVertices){
        return true;
    }
    for(int c=1; c<= numColours; c++){
        if(isSafe(v, c)){
            color[v] = c;
            if(graphColoringUtil(numColours, v+1)){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(int numColours){
    for(int i=0; i<numVertices; i++){
        color[i] = 0;
    }
    if(!graphColoringUtil(numColours, 0)){
        return false;
    }
    printSolution();
    return true;
}

void initializeGraph(){
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            graph[i][j] = 0;
        }
    }
}
int main(){

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initializeGraph();

    printf("\nEnter the adjacency matrix:\n");
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the number of colors: ");
    int numColours;
    scanf("%d", &numColours);

    if(!graphColoring(numColours)){
        printf("\nNo solution exists for the given graph and number of colors.\n");
    }

    return 0;
}