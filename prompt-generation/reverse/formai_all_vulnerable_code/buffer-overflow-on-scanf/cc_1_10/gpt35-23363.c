//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main(){
    char networkTopology[MAX][MAX], node[MAX][MAX], nodeType[MAX][MAX];
    int numOfNodes, numOfEdges = 0, numOfHosts = 0, numOfRouters = 0;
    int connectivityMatrix[MAX][MAX];
    printf("***Welcome to Network Topology Mapper***\n");
    printf("\nEnter the number of nodes in your network topology: ");
    scanf("%d", &numOfNodes);
    getchar(); //Clear input buffer
    for(int i=0; i<numOfNodes; i++){
        printf("Enter name of Node %d: ", i+1);
        scanf("%[^\n]s", node[i]);
        getchar(); //Clear input buffer
        printf("Enter type of Node %d (Router/Host): ", i+1);
        scanf("%[^\n]s", nodeType[i]);
        getchar(); //Clear input buffer
        if(strcmp(nodeType[i], "Router") == 0){
            numOfRouters++;
        }
        else{
            numOfHosts++;
        }
    }
    printf("\nEnter the connectivity matrix: \n");
    for(int i=0; i<numOfNodes; i++){
        for(int j=0; j<numOfNodes; j++){
            scanf("%d", &connectivityMatrix[i][j]);
            if(connectivityMatrix[i][j] == 1){
                numOfEdges++;
            }
        }
    }
    printf("\nNetwork Topology Map:\n");
    printf("\nNumber of Nodes: %d\nNumber of Hosts: %d\nNumber of Routers: %d\nNumber of Edges: %d\n", numOfNodes, numOfHosts, numOfRouters, numOfEdges);
    printf("\n%-10s", "Nodes");
    for(int i=0; i<numOfNodes; i++){
        printf("%-10s", node[i]);
    }
    printf("\n\n");
    for(int i=0; i<numOfNodes; i++){
        printf("%-10s", node[i]);
        for(int j=0; j<numOfNodes; j++){
            printf("%-10d", connectivityMatrix[i][j]);
            if(connectivityMatrix[i][j] == 1){
                printf("(%s - %s)", node[i], node[j]);
            }
        }
        printf("\n");
    }
    return 0;
}