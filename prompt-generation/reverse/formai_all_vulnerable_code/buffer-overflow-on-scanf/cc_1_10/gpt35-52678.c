//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct{
    int source;
    int dest;
} Edge;

int numNodes;
int numEdges;
int adjMatrix[MAX_NODES][MAX_NODES];
Edge edgeList[MAX_EDGES];

void clearMatrix(){
    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            adjMatrix[i][j] = 0;
        }
    }
}

void createEdgeList(){
    int i = 0;
    for(int s = 0; s < numNodes; s++){
        for(int d = 0; d < numNodes; d++){
            if(adjMatrix[s][d]){
                Edge e = {s, d};
                edgeList[i] = e;
                i++;
            }
        }
    }
}

int main(){
    printf("=================\n");
    printf("Network Topology Mapper\n");
    printf("=================\n\n");
    printf("Enter the number of nodes in the network (maximum %d): ", MAX_NODES);
    scanf("%d", &numNodes);

    if(numNodes > MAX_NODES){
        printf("\nError: Maximum number of nodes exceeded.\n");
        return 1;
    }

    printf("\nEnter the number of edges in the network (maximum %d): ", MAX_EDGES);
    scanf("%d", &numEdges);

    if(numEdges > MAX_EDGES){
        printf("\nError: Maximum number of edges exceeded.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix representing the network.\n");
    printf("\nNote: Enter 1 if there is an edge connecting the nodes,\n      and 0 if there is no edge.\n\n");

    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            printf("Enter the value for adjacency matrix[%d][%d]: ", i, j);
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    clearMatrix();
    createEdgeList();

    printf("\nNetwork Topology:\n");
    printf("------------------\n");
    printf("Nodes: %d\n", numNodes);
    printf("Edges: %d\n", numEdges);

    printf("\nEdge List:\n");
    printf("----------\n");

    for(int i = 0; i < numEdges; i++){
        Edge e = edgeList[i];
        printf("%d -> %d\n", e.source, e.dest);
    }

    return 0;
}