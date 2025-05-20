//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include<stdio.h>

//Function to find the shortest path using Dijkstra's Algorithm
void dijkstra(int n, int startVertex, int adjMatrix[20][20], int shortestDist[20]){

    int visited[20], count, mindist, nextVertex, i, j;

    //Initialize values
    for(i=0;i<n;i++){
        visited[i] = 0;
        shortestDist[i] = adjMatrix[startVertex][i];
    }

    //Initialize the starting vertex as visited
    visited[startVertex] = 1;
    count = 1;

    //Main loop for Dijkstra's Algorithm
    while(count<n-1){

        mindist = 99999;

        //Find the next vertex to visit
        for(i=0;i<n;i++){
            if(shortestDist[i]<mindist && !visited[i]){
                mindist = shortestDist[i];
                nextVertex = i;
            }
        }

        //Visit the next vertex
        visited[nextVertex] = 1;

        //Update the shortest distances of the vertices
        for(i=0;i<n;i++){
            if(!visited[i]){
                if(mindist+adjMatrix[nextVertex][i] < shortestDist[i]){
                    shortestDist[i] = mindist+adjMatrix[nextVertex][i];
                }
            }
        }
        count++;
    }

    //Print the shortest distance of each vertex from the starting vertex
    for(i=0;i<n;i++){
        if(i!=startVertex){
            printf("\nShortest distance from vertex %d to vertex %d is %d",startVertex,i,shortestDist[i]);
        }
    }
}

int main(){

    //Initialize variables and Adjacency Matrix for the graph
    int n = 6, startVertex = 0, i, j, adjMatrix[20][20], shortestDist[20];

    //Populating the adjacency matrix with weight for each edge
    printf("Enter the weights of the edges in the graph (in increasing order of the vertex number from 0 to n-1):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adjMatrix[i][j]);
        }
    }

    //Calling the dijkstra function to find the shortest path
    dijkstra(n,startVertex,adjMatrix,shortestDist);

    return 0;
}