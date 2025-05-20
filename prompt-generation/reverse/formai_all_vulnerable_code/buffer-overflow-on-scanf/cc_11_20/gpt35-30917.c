//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100 // Maximum nodes allowed

int main(){
    int numNodes; // Number of nodes
    int adjMatrix[MAX_NODES][MAX_NODES]; // Adjacency matrix

    // Input
    printf("Enter the number of nodes: ");
    scanf("%d",&numNodes);

    // Generate random adjacency matrix
    int i,j;
    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            if(rand()%2==0)
                adjMatrix[i][j]=0;
            else
                adjMatrix[i][j]=1;
        }
    }

    // Display the adjacency matrix
    printf("Adjacency Matrix\n");
    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Generate network topology map
    int adjList[MAX_NODES][MAX_NODES+1]; // Adjacency list
    int deg[MAX_NODES]; // Degree of each node

    // Initialize degree array to 0
    for(i=0;i<numNodes;i++){
        deg[i]=0;
    }

    // Initialize adjacency list
    for(i=0;i<numNodes;i++){
        adjList[i][0]=0; // Initialize degree of ith node to 0
        for(j=1;j<=numNodes;j++){
            adjList[i][j]=-1; // Initialize adjacent vertices to -1
        }
    }

    // Fill adjacency list
    for(i=0;i<numNodes;i++){
        for(j=0;j<numNodes;j++){
            if(adjMatrix[i][j]==1){
                adjList[i][adjList[i][0]+1]=j;
                adjList[i][0]++;
                deg[i]++; // Increment degree of ith node
            }
        }
    }

    // Display network topology map
    printf("\nNetwork Topology Map\n");
    for(i=0;i<numNodes;i++){
        printf("%d: ",i);
        for(j=1;j<=adjList[i][0];j++){
            printf("%d ",adjList[i][j]);
        }
        printf("\n");
    }

    // Display degrees of all nodes
    printf("\nDegrees of all nodes\n");
    for(i=0;i<numNodes;i++){
        printf("%d: %d\n",i,deg[i]);
    }

    return 0;
}