//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

/* Global Variables */
int graph[MAX][MAX];
int colorList[MAX];
int numberOfVertices;
int numberOfColors;

/* Function to check whether it is safe to assign color to a particular vertex */
int isSafe(int vertex, int color){
    for(int i=0; i<numberOfVertices; i++){
        if(graph[vertex][i] && colorList[i]==color){
            return 0;
        }
    }
    return 1;
}

/* Function to print the solution */
void printSolution(){
    printf("The assigned colors are:\n");
    for(int i=0; i<numberOfVertices; i++){
        printf("Vertex %d - Color %d\n", i+1, colorList[i]);
    }
}

/* Function to perform the graph coloring */
void graphColoring(int vertex){
    if(vertex==numberOfVertices){
        printSolution();
        exit(0);
    }
    for(int i=1; i<=numberOfColors; i++){
        if(isSafe(vertex, i)){
            colorList[vertex] = i;
            graphColoring(vertex+1);
            colorList[vertex] = 0;
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &numberOfVertices);
    printf("Enter the adjacency matrix of the graph:\n");
    for(int i=0; i<numberOfVertices; i++){
        for(int j=0; j<numberOfVertices; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &numberOfColors);
    graphColoring(0);
    printf("Solution does not exist!\n");
    return 0;
}