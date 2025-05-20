//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

//Defining maximum number of vertices
#define MAXV 100

//Creating an array to store all the vertices
int Vertices[MAXV];

//Creating a structure for the edges
struct edge{ 
int vertex1, vertex2;
};

//Creating an array to store all the edges
struct edge Edges[MAXV];

//Defining a global variable to store the number of vertices and edges
int NumVertices, NumEdges;

//Function to read the input graph from the user
void readGraph(){
    printf("\nEnter the number of vertices: ");
    scanf("%d", &NumVertices);
    printf("\nEnter the number of edges: ");
    scanf("%d", &NumEdges);
    printf("\nEnter the edges:\n");
    for(int i=0; i<NumEdges; i++){
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        Edges[i].vertex1 = v1;
        Edges[i].vertex2 = v2;
    }
}

//Function to initialize the vertices
void initVertices(){
    for(int i=0; i<NumVertices; i++) 
        Vertices[i] = -1;
}

//Function to color the graph
void colorGraph(){
    for(int i=0; i<NumVertices; i++){
        //Getting the adjacent vertices
        int adjVertices[MAXV], count=0;
        for(int j=0; j<NumEdges; j++){
            if(Edges[j].vertex1 == Vertices[i]) 
                adjVertices[count++] = Edges[j].vertex2;
            else if(Edges[j].vertex2 == Vertices[i]) 
                adjVertices[count++] = Edges[j].vertex1;
        }

        //Checking the colors of adjacent vertices
        int colorUsed[MAXV] = {0};
        for(int j=0; j<count; j++)
            if(Vertices[adjVertices[j]] != -1) 
                colorUsed[Vertices[adjVertices[j]]] = 1;

        //Choosing the minimum available color
        for(int j=0; j<NumVertices; j++)
            if(colorUsed[j] == 0){
                Vertices[i] = j;
                break;
            }
    }
}

//Function to print the colored graph
void printGraph(){
    printf("\n The colored graph is:\n");
    for(int i=0; i<NumVertices; i++) printf("%d ", Vertices[i]);
    printf("\n");
}

//Main function
int main(){
    readGraph();
    initVertices();
    colorGraph();
    printGraph();
    return 0;
}