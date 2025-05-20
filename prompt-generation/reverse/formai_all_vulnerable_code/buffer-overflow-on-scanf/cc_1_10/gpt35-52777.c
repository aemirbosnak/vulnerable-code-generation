//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#define maxVertices 100

int graph[maxVertices][maxVertices];
int color[maxVertices];

void coloring(int vertex, int c, int vertices){

    for(int i=0;i<vertices;i++){    //checking the adjacent vertices
        if(graph[vertex][i] != 0){
            if(color[i] == c){      //if adjacent vertex has same color, return
                return;
            }
        }
    }
    color[vertex] = c;             //assigning color to vertex
    
    //Coloring the remaining vertices
    for(int i=1;i<=vertices;i++){
        if(color[i] == 0){
            for(int k=1;k<=vertices;k++){
                coloring(i,k,vertices);
            }
        }
    }
}

int main(){
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    //Initialising all the vertices to 0 color
    for(int i=0;i<=vertices;i++){
        color[i] = 0;
    }

    //Creating the graph
    printf("Enter the edges (src, dest):\n");
    for(int i=0;i<edges;i++){
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    //Coloring the graph
    for(int i=1;i<=vertices;i++){
        for(int j=1;j<=vertices;j++){
            if(graph[i][j] == 0){
                graph[i][j] = 0;
            }
        }
    }

    for(int i=1;i<=vertices;i++){
        if(color[i] == 0){
            for(int k=1;k<=vertices;k++){   //apply coloring to vertices if it is not colored
                coloring(i,k,vertices);
            }
        }
    }

    //Printing the vertices with their colors
    printf("\nVertices with colors:\n");
    for(int i=1;i<=vertices;i++){
        printf("Vertex %d : Color %d\n", i, color[i]);
    }

    return 0;
}