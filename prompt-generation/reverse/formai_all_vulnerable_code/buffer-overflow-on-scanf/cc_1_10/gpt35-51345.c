//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numOfVertices;                  // Number of vertices in the graph
int *color;                         // An array to store the color of each vertex
int **graph;                        // An adjacency matrix to represent the graph

// Function to initialize the graph with random values
void initializeGraph(){
    graph = (int **) malloc(sizeof(int *) * numOfVertices);
    for(int i=0; i<numOfVertices; i++){
        graph[i] = (int *) malloc(sizeof(int) * numOfVertices);
        for(int j=0; j<numOfVertices; j++){
            graph[i][j] = rand() % 2;
        }
    }
}

// Function to print the graph
void printGraph(){
    for(int i=0; i<numOfVertices; i++){
        for(int j=0; j<numOfVertices; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a vertex can be assigned a particular color or not
bool canAssignColor(int v, int c){
    for(int i=0; i<numOfVertices; i++){
        if(graph[v][i] && color[i] == c){
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem recursively
bool solveGraph(int v){
    if(v == numOfVertices){
        return true;
    }
    for(int i=1; i<=numOfVertices; i++){
        if(canAssignColor(v, i)){
            color[v] = i;
            if(solveGraph(v+1)){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

int main(){
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numOfVertices);
    initializeGraph();
    printf("The graph is:\n");
    printGraph();
    color = (int *) calloc(numOfVertices, sizeof(int));
    if(solveGraph(0)){
        printf("The graph can be colored using the following colors:\n");
        for(int i=0; i<numOfVertices; i++){
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    } else{
        printf("The graph cannot be colored using %d colors.\n", numOfVertices);
    }
    return 0;
}