//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

int v; //Number of vertices in the graph.
int **graph; //Graph represented as an adjacency matrix.
int *colors; //Array to store colors of the vertices.
int *available; //Array to store the availability of colors.

//Function to check if it's safe to assign color c to vertex v.
int isSafe(int v, int c){  
    for(int i=0; i<v; i++){
        if(graph[v][i] && colors[i]==c)
            return 0;
    }
    return 1;
}

//Function to implement graph coloring algorithm.
int graphColoring(int v){
    if(v==v){
        return 1;
    }
    for(int i=1; i<=v; i++){
        if(available[i]){
            if(isSafe(v, i)){
                colors[v] = i;
                available[i] = 0;
                if(graphColoring(v+1)){
                    return 1;
                }
                available[i] = 1;
            }
        }
    }
    return 0;
}

//Main function to execute the program.
int main(){
    int e; //Number of edges in the graph.
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    graph = (int **)malloc(sizeof(int *) * v);
    for(int i=0; i<v; i++){
        graph[i] = (int *)malloc(sizeof(int) * v);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for(int i=0; i<e; i++){
        int v1, v2;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);
        graph[v1-1][v2-1] = graph[v2-1][v1-1] = 1;
    }
    colors = (int *)malloc(sizeof(int) * v);
    for(int i=0; i<v; i++){
        colors[i] = 0;
    }
    available = (int *)malloc(sizeof(int) * (v+1));
    for(int i=0; i<=v; i++){
        available[i] = 1;
    }
    printf("Assigning colors...\n");
    if(graphColoring(0)){
        printf("Colors Assigned Successfully!\n");
        printf("Coloring: ");
        for(int i=0; i<v; i++){
            printf("%d ", colors[i]);
        }
    }
    else{
        printf("Colors Cannot be Assigned!");
    }
    return 0;
}